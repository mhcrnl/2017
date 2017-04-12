/* main.c
 *
 * Copyright (C) 2017 mhcrnl
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

static void
print_hello(GtkWidget *widget, gpointer data){
  g_print("Salut!\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "myproject01");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  /* You can add GTK+ widgets to your window here.
   * See https://developer.gnome.org/ for help.
   */

  gtk_widget_show (window);
}

int main(int   argc,
         char *argv[])
{
  g_autoptr(GtkApplication) app = NULL;
  int status;

  app = gtk_application_new ("org.gnome.Myproject01", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);

  return status;
}
