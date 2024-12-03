#include "../headers/app.h"
#include "../headers/mainwnd.h"

struct _RunoApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(RunoApp, runo_app, GTK_TYPE_APPLICATION);

/* Инициализация приложения (метод вызывается внутри gtk) */
static void runo_app_init(RunoApp *app) {

}

/* Активация главного окна приложения */
static void runo_app_activate(GApplication *app) {
    RunoAppWindow *win;

    win = runo_app_window_new(RUNO_APP(app));
    gtk_window_present(GTK_WINDOW(win));
}

/* Метод выхода из приложения */
static void quit_activated(GSimpleAction *_action, GVariant *_parameter, gpointer app) {
  g_application_quit(G_APPLICATION(app));
}

/* Метод запуска окна настроек */
static void preferences_activated(GSimpleAction *action, GVariant *parameter, gpointer app) {

}

/* Обработчики меню приложения */
static GActionEntry app_entries[] = {
    { "preferences", preferences_activated, NULL, NULL, NULL },
    { "quit", quit_activated, NULL, NULL, NULL }
};

/* Инициализация компонентов приложения (меню) */
static void runo_app_startup(GApplication *app) {
    // const char *quit_accels[2] = { "<Ctrl>Q", NULL };

    G_APPLICATION_CLASS(runo_app_parent_class)->startup(app);

    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entries, G_N_ELEMENTS (app_entries), app);
    // gtk_application_set_accels_for_action(GTK_APPLICATION(app), "app.quit", quit_accels);
}

/* Инициализация класса приложения (метод вызывается внутри gtk) */
static void runo_app_class_init(RunoAppClass *class) {
    
    G_APPLICATION_CLASS(class)->activate = runo_app_activate;
    G_APPLICATION_CLASS(class)->startup = runo_app_startup;
    // G_APPLICATION_CLASS(class)->open = runo_app_open;
}

/* Создание объекта приложения */
RunoApp *runo_app_new(void) {
    return g_object_new(RUNO_APP_TYPE, "application-id", "ru.axel.tl", "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}
