#include <signal.h>
#include <unistd.h>
#include "mraa.hpp"

bool running = true;
bool relay_state = false;
int last_touch;
void sig_handler(int signo)
{
        if (signo == SIGINT)
                running = false;
}
int main(int argc, char* argv[])
{
        mraa::Gpio* touch_gpio = new mraa::Gpio(29);
        mraa::Gpio* relay_gpio = new mraa::Gpio(27);
        mraa::Result response;
        int touch;

        signal(SIGINT, sig_handler);

        response = touch_gpio->dir(mraa::DIR_IN);
        if (response != mraa::SUCCESS)
                return 1;
        response = relay_gpio->dir(mraa::DIR_OUT);
        if (response != mraa::SUCCESS)
                return 1;

        relay_gpio->write(relay_state);
        
        while (running) {
                touch = touch_gpio->read();
                if (touch == 1 && last_touch == 0) {
                        relay_state = !relay_state;
                        response = relay_gpio->write(relay_state);
                        usleep(100000);
                }
                last_touch = touch;
        }
        delete relay_gpio;
        delete touch_gpio;
        return response;
}

