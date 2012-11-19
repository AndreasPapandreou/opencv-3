/*
 * This project is to demonstrate all kinds of opencv
 * functionality. If you find any bugs or have any questions,
 * please feel free to email me.
 *
 * Date: 18/11/2012
 * Author: ycshao
 * Email: ycshao0402@gmail.com
 */

#include <gtk/gtk.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <stdio.h>

gint t = 0;
IplImage* opencvImage;
GdkPixbuf* pix;
CvCapture* capture;

static gboolean time_handler( GtkWidget *widget ) {
  return TRUE;
}

gboolean expose_event_callback( GtkWidget      *widget,
                                GdkEventExpose *event,
                                gpointer        data) {
   gtk_widget_queue_draw( GTK_WIDGET( widget ));
   opencvImage = cvQueryFrame( capture );
   cvCvtColor( opencvImage, opencvImage, CV_BGR2RGB );
   pix = gdk_pixbuf_new_from_data(( guchar* )opencvImage->imageData,
                                             GDK_COLORSPACE_RGB,
                                             FALSE,
                                             opencvImage->depth,
                                             opencvImage->width,
                                             opencvImage->height,
                                             ( opencvImage->widthStep ),
                                             NULL, NULL);
   cairo_t* cr = gdk_cairo_create(gtk_widget_get_window(widget));
   gdk_cairo_set_source_pixbuf(cr, pix, 0, 0);
   cairo_paint(cr);

//   gdk_draw_pixbuf( widget->window,
//                    widget->style->fg_gc[ GTK_WIDGET_STATE( widget )],
//                    pix,
//                    0, 0, 0, 0,
//                    opencvImage->width,
//                    opencvImage->height,
//                    GDK_RGB_DITHER_MAX,
//                    0, 0);
   return TRUE;
}

int main( int argc, char *argv[] ) {
   GtkWidget *window;
   GtkWidget *drawing_area;

   gtk_init (&argc, &argv);
   capture = cvCaptureFromCAM( CV_CAP_ANY );
   opencvImage = cvQueryFrame( capture );
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title( GTK_WINDOW( window ), "WEBCAM");
   g_signal_connect( G_OBJECT( window ), "destroy", G_CALLBACK (gtk_main_quit), NULL);
   drawing_area = gtk_drawing_area_new();
   gtk_widget_set_size_request( drawing_area, opencvImage->width, opencvImage->height );
   gtk_container_add( GTK_CONTAINER( window ), drawing_area );
   gtk_widget_show( drawing_area );
   g_signal_connect( G_OBJECT( drawing_area), "expose_event", G_CALLBACK (expose_event_callback), NULL);
   g_timeout_add( 100, ( GSourceFunc )time_handler, ( gpointer )drawing_area );
   gtk_widget_show(window);
   gtk_main();
   cvReleaseCapture( &capture );
   return 0;
}
//#include "fileChooser.h"
//#include <gtkmm/main.h>
//
//int main(int argc, char *argv[])
//{
//  Gtk::Main kit(argc, argv);
//
//  FileChooser window;
//  window.set_default_size(300, 40);
//  //Shows the window and returns when it is closed.
//  Gtk::Main::run(window);
//
//  return 0;
//}

