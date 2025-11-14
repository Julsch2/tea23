#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <thread>
#include <chrono>

// ---------- Funktionsprototypen ----------
void set_state_move_up(void);
void set_state_move_down(void);
void set_state_stop(void);


// ----------------------------------------------------
int main(int argc, char **argv) {

    enum class states {
        move_down,
        move_up,
        stop_down,
        stop_up,
        is_down,
        is_up
    };

    states current_state = states::move_up;

    struct Inputs {
        bool Taster;
        bool Endschalter_Oben;
        bool Endschalter_Unten;
    };

    std::vector<Inputs> sim = {
        {false, false, false},
        {false, false, false},
        {true,  false, false},
        {false, false, false},
        {false, true,  false},
        {true,  true,  false},
        {false, false, false},
        {false, false, true},
        {true,  false, true},
        {false, false, false},
        {false, true,  false},
        {false, true,  false},
    };


    for (size_t i = 0; i < sim.size(); ++i) {

        auto in = sim[i];

        fmt::print("\n--- Schritt {} ---\n", i);
        fmt::print("Taster={}  Oben={}  Unten={}\n",
            in.Taster, in.Endschalter_Oben, in.Endschalter_Unten);


        switch(current_state){

            // ----------------------------------------------------
            case states::move_up:
                fmt::print("Zustand: fahre hoch\n");

                if (in.Endschalter_Oben) {
                    current_state = states::is_up;
                    set_state_stop();
                }
                else if (in.Taster) {
                    current_state = states::stop_up;
                    set_state_stop();
                }
                else {
                    set_state_move_up();   
                }
                break;


            // ----------------------------------------------------
            case states::stop_up:
                fmt::print("Zustand: stoppe oben\n");

                if (in.Taster) {
                    current_state = states::move_down;
                }
                else {
                    set_state_stop();
                }
                break;


            // ----------------------------------------------------
            case states::move_down:
                fmt::print("Zustand: fahre runter\n");

                if (in.Endschalter_Unten) {
                    current_state = states::is_down;
                    set_state_stop();
                }
                else if (in.Taster) {
                    current_state = states::stop_down;
                    set_state_stop();
                }
                else {
                    set_state_move_down();  
                }
                break;


            // ----------------------------------------------------
            case states::stop_down:
                fmt::print("Zustand: stoppe unten\n");

                if (in.Taster) {
                    current_state = states::move_up;
                }
                else {
                    set_state_stop();
                }
                break;


            // ----------------------------------------------------
            case states::is_up:
                fmt::print("Zustand: ist oben\n");

                if (in.Taster) {
                    current_state = states::move_down;
                }
                else {
                    set_state_stop();
                }
                break;


            // ----------------------------------------------------
            case states::is_down:
                fmt::print("Zustand: ist unten\n");

                if (in.Taster) {
                    current_state = states::move_up;
                }
                else {
                    set_state_stop();
                }
                break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    return 0;
}

 

void set_state_move_up(void){
    fmt::print(" → Aktion: Tor fährt nach oben\n");
}

void set_state_move_down(void){
    fmt::print(" → Aktion: Tor fährt nach unten\n");
}

void set_state_stop(void){
    fmt::print(" → Aktion: Tor stoppt\n");
}
