#include <gtk/gtk.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>

void on_app_destroy (void)
{
        gtk_main_quit ();
}
int main(int argc, char *argv[])
{
        GtkBuilder *gtkBuilder;
        GtkWidget *app;
        gtk_init(&argc, &argv);

        gtkBuilder = gtk_builder_new();
        gtk_builder_add_from_file(gtkBuilder, ".glade/mainwindow.glade", NULL);
        app = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "MainWindowDialog"));

        g_object_unref(G_OBJECT(gtkBuilder));
        gtk_widget_show(app);
        gtk_main();

        return 0;
}
