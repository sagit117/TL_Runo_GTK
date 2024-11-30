#include <gtk/gtk.h>

#include "../headers/mainwnd.h"

/* Запуск приложения */
int launch_app(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("ru.axel.tl", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate_mainwnd), NULL);
    int status = g_application_run(G_APPLICATION(app), 1, argv); // Передаем только 1 аргумент (название приложение, что-бы не вылетала ошибка "Неизвестный параметр")
    g_object_unref(app);

    return status;
}