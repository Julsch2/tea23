#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <thread>
#include <chrono>

#include "config.h"

int main(int argc, char **argv) {

    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    enum class states {
        move_down,
        move_up,
        stop_down,
        stop_up,
        is_down,
        is_up
    };

    states current_state = states::move_up;

    // -----------------------------
    // INPUT SIMULATION
    // -----------------------------
    struct Inputs {
        bool Taster;              // true = gedrückt
        bool Endschalter_Oben;    // true = oben erreicht
        bool Endschalter_Unten;   // true = unten erreicht
    };

    // Beispiel-Simulation für 12 Schritte
    std::vector<Inputs> sim = {
        {false, false, false},   // 0 — fährt hoch
        {false, false, false},   // 1 — fährt hoch
        {true,  false, false},   // 2 — Taster stoppt oben
        {false, false, false},   // 3
        {false, true,  false},   // 4 — oben erreicht
        {true,  true,  false},   // 5 — Taster → Fahrt runter
        {false, false, false},   // 6 — fährt runter
        {false, false, true},    // 7 — unten erreicht
        {true,  false, true},    // 8 — Taster → hoch
        {false, false, false},   // 9
        {false, true,  false},   // 10 — oben erreicht
        {false, true,  false},   // 11
    };

    // -----------------------------
    // MAIN LOOP
    // -----------------------------
    for (size_t i = 0; i < sim.size(); ++i) {

        auto in = sim[i];

        fmt::print("\n--- Schritt {} ---\n", i);
        fmt::print("Taster={}  Oben={}  Unten={}\n",
            in.Taster, in.Endschalter_Oben, in.Endschalter_Unten);

        switch(current_state){

            case states::move_up:
                fmt::print("Zustand: fahre hoch\n");

                if (in.Endschalter_Oben)
                    current_state = states::is_up;
                else if (in.Taster)
                    current_state = states::stop_up;

                break;

            case states::stop_up:
                fmt::print("Zustand: stoppe oben\n");

                if (in.Taster)
                    current_state = states::move_down;

                break;

            case states::move_down:
                fmt::print("Zustand: fahre runter\n");

                if (in.Endschalter_Unten)
                    current_state = states::is_down;
                else if (in.Taster)
                    current_state = states::stop_down;

                break;

            case states::stop_down:
                fmt::print("Zustand: stoppe unten\n");

                if (in.Taster)
                    current_state = states::move_up;

                break;

            case states::is_up:
                fmt::print("Zustand: ist oben\n");

                if (in.Taster)
                    current_state = states::move_down;

                break;

            case states::is_down:
                fmt::print("Zustand: ist unten\n");

                if (in.Taster)
                    current_state = states::move_up;

                break;
        }

        // kleine Pause, damit die Ausgabe lesbar bleibt
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    return 0;
}
