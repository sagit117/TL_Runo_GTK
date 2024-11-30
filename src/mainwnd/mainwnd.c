#include "../headers/mainwnd.h"

static void quit_activated(GSimpleAction *action, GVariant *parameter, gpointer app) {
  g_application_quit(G_APPLICATION(app));
}

static GActionEntry app_entries[] = {
//   { "preferences", preferences_activated, NULL, NULL, NULL },
    { "quit", quit_activated, NULL, NULL, NULL }
};

/* Метод активации главного окна */
void activate_mainwnd(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "./src/mainwnd/mainwnd.ui", NULL);

    GObject *window = gtk_builder_get_object(builder, "window");
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
    // gtk_window_maximize(GTK_WINDOW(window));

    GMenuModel *menu;
    GObject *button = gtk_builder_get_object(builder, "topmenu");

    builder = gtk_builder_new_from_file("./src/ui/topmenu.ui");
    
    menu = G_MENU_MODEL(gtk_builder_get_object(builder, "menu"));
    gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(button), menu);
    // gtk_menu_button_set_primary (GTK_MENU_BUTTON (button), TRUE);

    g_action_map_add_action_entries(G_ACTION_MAP (app), app_entries, G_N_ELEMENTS (app_entries), app);

    g_object_unref(builder);
}