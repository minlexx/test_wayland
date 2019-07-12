#include <iostream>
#include <wayland-client.h>
#include <wayland-version.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    struct wl_display *disp = wl_display_connect(nullptr);
    if (!disp) {
        std::cerr << "Failed to connect to wayland display!" << std::endl;
        return 1;
    }
    
    std::cout << "Connect OK!" << std::endl;
    
    wl_display_disconnect(disp);
    return 0;
}
