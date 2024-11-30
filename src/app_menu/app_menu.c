#include "../headers/app_menu.h"

static void quit_activated(GSimpleAction *action, GVariant *parameter, gpointer app) {
  g_application_quit(G_APPLICATION(app));
}

static GActionEntry app_entries[] = {
//   { "preferences", preferences_activated, NULL, NULL, NULL },
    { "quit", quit_activated, NULL, NULL, NULL }
};

void set_app_menu_model(GtkMenuButton *button, GtkApplication *app) {
    GtkBuilder *builder = gtk_builder_new_from_file("./src/app_menu/app_menu.ui");
    GMenuModel *menu = G_MENU_MODEL(gtk_builder_get_object(builder, "app_menu"));

    gtk_menu_button_set_menu_model(button, menu);
    gtk_menu_button_set_primary(GTK_MENU_BUTTON (button), TRUE);

    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entries, G_N_ELEMENTS(app_entries), app);

    g_object_unref(builder);
}