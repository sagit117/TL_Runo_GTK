#include "../headers/mainwnd.h"
#include "../headers/app_menu.h"

/** 
 * Метод активации главного окна.
 * @param app объект приложения.
 * @param _user_data параметры.
 */
void activate_mainwnd(GtkApplication *app, gpointer _user_data) {
    GtkBuilder *builder = gtk_builder_new_from_file("./src/mainwnd/mainwnd.ui");
    GObject *window = gtk_builder_get_object(builder, "window");

    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
    // gtk_window_maximize(GTK_WINDOW(window));

    GObject *button_app_menu = gtk_builder_get_object(builder, "app_menu_btn");
    set_app_menu_model(GTK_MENU_BUTTON(button_app_menu), app);

    g_object_unref(builder);
}