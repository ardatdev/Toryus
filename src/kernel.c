#include <terminal.h>
#include <dt.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <timer.h>
#include <keyboard.h>
#include <serial.h>
#include <string.h>
#include <io.h>
#include <shell.h>

/* Toryus Kernel main function */
void kernel_main(void)
{
  serial_init();
  serial_log("knl", "Initializing");
  serial_log("dts", "Initializing");
  init_descriptor_tables();
  serial_log("tty", "Initializing");
  terminal_initialize();
  serial_log("pit", "Initializing");
  timer_init(1000);
  serial_log("kbd", "Initializing");
  keyboard_init();
  serial_log("knl", "Initialized");

  // Toryus logo
  terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  terminal_print(
    "                ##                \n"
    "              ##  ##     ####");
  terminal_setcolor(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
  terminal_print("###  \n");
  terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  terminal_print("            ##      ##  #    ");
  terminal_setcolor(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
  terminal_print("#### \n");
  terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  terminal_print("          ##          ###     ");
  terminal_setcolor(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
  terminal_print("### \n");
  terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  terminal_print(
    "        ##              ##     #  \n"
    "      ##                  #####   \n"
    "    ##                      ##    \n"
    "  ##                          ##  \n"
    "##              ##              ##\n"
    "  ##              ##          ##  \n"
    "    ##              ##      ##    \n"
    "      ##              ##  ##      \n"
    "        ##              ##        \n"
    "          ##          ##          \n"
    "            ##      ##            \n"
    "              ##  ##              \n"
    "                ##                \n"
    "Welcome to Toryus!\n"
  );
  shell_exec();
}
/*

*/