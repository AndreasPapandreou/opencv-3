/*
 * This project is to demonstrate all kinds of opencv
 * functionality. If you find any bugs or have any questions,
 * please feel free to email me.
 *
 * Date: 18/11/2012
 * Author: ycshao
 * Email: ycshao0402@gmail.com
 */

#include "fileChooser.h"
#include <gtkmm/main.h>

int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  FileChooser window;
  window.set_default_size(300, 40);
  //Shows the window and returns when it is closed.
  Gtk::Main::run(window);

  return 0;
}

