#include "../headers/mainwnd.h"
#include "../headers/app_menu.h"

// static void quit_activated(GSimpleAction *action, GVariant *parameter, gpointer app) {
//   g_application_quit(G_APPLICATION(app));
// }

// static GActionEntry app_entries[] = {
// //   { "preferences", preferences_activated, NULL, NULL, NULL },
//     { "quit", quit_activated, NULL, NULL, NULL }
// };

/* Метод активации главного окна */
void activate_mainwnd(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder = gtk_builder_new_from_file("./src/mainwnd/mainwnd.ui");
    GObject *window = gtk_builder_get_object(builder, "window");

    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
    // gtk_window_maximize(GTK_WINDOW(window));

    // GMenuModel *menu;
    GObject *button_app_menu = gtk_builder_get_object(builder, "app_menu_btn");
    set_app_menu_model(GTK_MENU_BUTTON(button_app_menu), app);

    g_object_unref(builder);
}