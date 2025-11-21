#include <fmt/chrono.h>
#include <fmt/format.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "CLI/CLI.hpp"
#include "config.h"
#include "image.h"



auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    // print length of array 
    int length_img_array = sizeof(image)/sizeof(image[0]);
    fmt::print("Länge des Arrays: {}", length_img_array);


    // image ist const unsigned char*, Länge ist width * height * 3 (für RGB)
    cv::Mat img(image_height, image_width, CV_8UC3, (void*)image); 

    // img kann jetzt direkt genutzt werden, z.B. Image anzeigen oder Parameter ausgeben
    fmt::println("OpenCV Bild-Parameter:");
    fmt::println("Breite: {}", img.cols);
    fmt::println("Höhe: {}", img.rows);
    fmt::println("Kanäle: {}", img.channels());
    


    return 0; /* exit gracefully*/
}
