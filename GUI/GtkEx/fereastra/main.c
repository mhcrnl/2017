#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
    GtkWidget *fereastra;
    gtk_init(&argc, &argv);
    fereastra = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(fereastra);
    g_signal_connect(fereastra, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return 0;
}
