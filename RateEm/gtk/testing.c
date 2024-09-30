//gcc testing.c -o main `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
//https://www.youtube.com/watch?v=n64A7GvcjQU&list=PLEs_0O72adQBUpcPJv7dKaElGwyzVljtk&index=2

#include <gtk/gtk.h>

// Function to handle button click event
void button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button clicked!\n");
}

int main(int argc, char ** argv) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Title of the window
    gtk_window_set_title(GTK_WINDOW(window), "RateEm");

    // To set window into the centre
    //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Set default size of window
    //gtk_window_set_default_size(GTK_WINDOW(window), 500,400);

    // Set border between the widgets and sides of window
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    
    // Option for User to resize the window
    gtk_window_set_resizable(GTK_WINDOW(window),TRUE);


    // Close button to quit program
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container to implement many containers in same window
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *image_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), button_box);
    gtk_container_add(GTK_CONTAINER(window), image_box);

    // Load an image
    GtkWidget *image = gtk_image_new_from_file("casual.jpg"); 
    // Replace "image.jpg" with your image file path
    gtk_box_pack_start(GTK_BOX(image_box), image, TRUE, TRUE, 0);

    // Create button1
    GtkWidget *button1 = gtk_button_new_with_label("button1");
    //g_signal_connect(button1, "clicked", G_CALLBACK(button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(button_box), button1, TRUE, FALSE, 0);

    // Create button2
    GtkWidget *button2 = gtk_button_new_with_label("button2");
    //g_signal_connect(button2, "clicked", G_CALLBACK(button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(button_box), button2, TRUE, FALSE, 0);

    // Show all widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}
