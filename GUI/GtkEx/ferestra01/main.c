#include <gtk/gtk.h>

int main(int argc, char *argv[]){

    guint width = 450;
    guint height = 500;

    const gchar *titlu = "Fereastra aplicatiei 01";

    GtkWindow *fereastra;
    GtkWindow *vbox;
    GtkWindow *hbbox;
    GtkWidget *setari;
    GtkWidget *close;
    GtkWidget *ok;

    gtk_init(&argc, &argv);

    fereastra = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(fereastra, titlu);
    gtk_window_set_default_size(fereastra, width, height);
    gtk_window_set_position(fereastra, GTK_WIN_POS_CENTER_ALWAYS);
    //gtk_window_maximize(fereastra);

    vbox= gtk_vbox_new(TRUE, 1);
    gtk_container_add(GTK_CONTAINER(fereastra), vbox);
    hbbox = gtk_hbutton_box_new();

    setari = gtk_button_new_with_label("Setari");
    close = gtk_button_new_with_label("Close");
    ok = gtk_button_new_with_label("Ok");

    gtk_box_pack_start(GTK_BOX(vbox), setari, TRUE, TRUE,0);
    gtk_box_pack_start(GTK_BOX(vbox), close, TRUE, TRUE,0);
    gtk_box_pack_start(GTK_BOX(hbbox), ok, TRUE, TRUE,0);
    gtk_box_pack_start(GTK_BOX(vbox), hbbox, TRUE, TRUE,0);

    gtk_widget_show(fereastra);
    gtk_widget_show_all(fereastra);

    g_signal_connect(fereastra, "destroy", G_CALLBACK(gtk_main_quit),NULL);

    gtk_main();

    return 0;
}
