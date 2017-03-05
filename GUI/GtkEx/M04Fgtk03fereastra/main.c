#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
/**
    Fereastra realizata in GTK
*/
void print_msg(GtkWidget *widget, gpointer window){
    g_printf("Button apasat!\n");
}

GdkPixbuf *create_pixbuf(const gchar *filename){
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if(!pixbuf){
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}

int main(int argc, char *argv[]){
    /**
        GtkWidget este clasa de baza pt toate widget-urile si are ciclu de viata,
        stare si stil.
    */
    GtkWidget *fereastra;
    GdkPixbuf *icon;
    GtkWidget *button;
    GtkAccelGroup *accel_group = NULL;
    //GtkWidget *halign;
    GtkWidget *vbox;

    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *fileMi;
    GtkWidget *quitMi;
    GtkWidget *imprMenu;
    GtkWidget *sep;
    GtkWidget *imprMi;
    GtkWidget *feedMi;
    GtkWidget *mailMi;
    GtkWidget *bookMi;
    GtkWidget *newMi;
    GtkWidget *openMi;
    /**
        Functia initializeaza gtk si trebuie apelata inaitea a orice.
    */
    gtk_init(&argc, &argv);
    /**
        Creaza fereastra care este top-level si poate contine si alte widget-uri.
    */
    fereastra = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fereastra), "Fereastra principala centrata");
    gtk_window_set_default_size(GTK_WINDOW(fereastra), 850, 600);
    gtk_window_set_position(GTK_WINDOW(fereastra), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_WINDOW(fereastra),15);

    icon = create_pixbuf("web.png");
    gtk_window_set_icon(GTK_WINDOW(fereastra), icon);

    //button = gtk_button_new_with_label("BUTTON");
    button = gtk_button_new_with_mnemonic("_BUTTON");
    gtk_widget_set_tooltip_text(button, "Widget button");

    g_signal_connect(button, "clicked", G_CALLBACK(print_msg),NULL);

    //halign = gtk_alignment_new(0,0,0,0);
    vbox = gtk_vbox_new(FALSE, 0);
    //gtk_container_add(GTK_CONTAINER(halign), button);
    //gtk_container_add(GTK_CONTAINER(fereastra), halign);
    gtk_container_add(GTK_CONTAINER(fereastra), vbox);
    //creaza un nou GtkMenuBar pentru fereastra
    menubar = gtk_menu_bar_new();
    //Creaza un nou GtkMenu in care vor fi adaugati item file
    fileMenu = gtk_menu_new();

    accel_group = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(fereastra), accel_group);

    //fileMi = gtk_menu_item_new_with_label("File");
    fileMi = gtk_menu_item_new_with_mnemonic("_File");
    newMi = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
    openMi = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
    sep = gtk_separator_menu_item_new();
    quitMi = gtk_menu_item_new_with_label("Quit");
    quitMi = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);

    gtk_widget_add_accelerator(quitMi, "activate", accel_group,GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    imprMenu = gtk_menu_new();
    imprMi = gtk_menu_item_new_with_label("Import");
    feedMi = gtk_menu_item_new_with_label("Import news-feed...");
    bookMi = gtk_menu_item_new_with_label("Import bookmarks...");
    mailMi = gtk_menu_item_new_with_label("Import mail...");


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(imprMi), imprMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(imprMenu), feedMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(imprMenu), bookMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(imprMenu), mailMi);
    sep = gtk_separator_menu_item_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), imprMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), sep);
    //quitMi este adaugat in fileMenu
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),newMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),openMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar),fileMi);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE,0);
    /**
        Afiseaza fereastra orice widget care nu este afisat nu apare.
    */
    gtk_widget_show_all(fereastra);
    /**
        Functia leaga semnalul de inchidere de fereastra, nu este default.
    */
    g_signal_connect(fereastra, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(quitMi), "activate", G_CALLBACK(gtk_main_quit), NULL);

    g_object_unref(icon);
    /**
        Aceasta functie asteapta evenimentele intr-un loop.
    */
    gtk_main();
    return 0;
}
