#include "Parsing.h"
#include "MinuteHand.h"
#include "SecondHand.h"
#include "Clock.h"

#include <chrono>
#include <thread>
#include <iostream>

// You can call the program with the following command in order to queue 3 events at 2s, 1m3s and 10m :
// tp2-reminders.exe "0:2 This is the first reminder" "1:3 This is the second one" "10:0 And the last"

int main(int argc, char** argv)
{
    const auto events = parse_events(argc, argv);

    MinuteHand minute_hand;
    SecondHand second_hand(minute_hand);
    Clock clock(minute_hand, second_hand);
    for (const auto &item : events)
    {
        clock.add_event(item);
    }

    const auto program_duration = 86500;
    for (int i = 0; i < program_duration; ++i)
    {
        clock.tick();
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

//int main() {
//    MinuteHand minuteHand;
//    SecondHand secondHand(minuteHand);
//    Clock clock(minuteHand, secondHand);
//
//    std::cout << clock << std::endl;
//    for (auto i = 0; i < 63; i++) { clock.tick(); }
//    std::cout << clock << std::endl;
//}