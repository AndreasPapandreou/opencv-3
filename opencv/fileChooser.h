/*
 * FileChooser.h
 *
 *  Created on: Nov 18, 2012
 *      Author: ycshao
 */

#ifndef FILECHOOSER_H_
#define FILECHOOSER_H_

#include <gtkmm.h>

class FileChooser : public Gtk::Window
{
public:
  FileChooser();
  virtual ~FileChooser();

protected:
  //Signal handlers:
  void on_button_file_clicked();
  void on_button_folder_clicked();

  //Child widgets:
  Gtk::VButtonBox m_ButtonBox;
  Gtk::Button m_Button_File, m_Button_Folder;
};

#endif /* FILECHOOSER_H_ */
