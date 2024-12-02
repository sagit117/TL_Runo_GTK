// #include <gtk/gtk.h>

#include "../headers/app.h"
#include "../headers/mainwnd.h"

// struct _RunoApp {
//     GtkApplication parent;
// };

// G_DEFINE_TYPE(RunoApp, runo_app, GTK_TYPE_APPLICATION);

// static void runo_app_init(RunoApp *app) {

// }

// static void runo_app_activate(GApplication *app) {
// //   ExampleAppWindow *win;

// //   win = example_app_window_new (EXAMPLE_APP (app));
// //   gtk_window_present (GTK_WINDOW (win));
// }


// static void runo_app_class_init(RunoAppClass *class) {
//   G_APPLICATION_CLASS(class)->activate = runo_app_activate;
// //   G_APPLICATION_CLASS(class)->open = example_app_open;
// }

// RunoApp *runo_app_new(void) {
//     return g_object_new(sizeof(RUNO_APP), "application-id", "ru.axel.tl", "flags", G_APPLICATION_HANDLES_OPEN, NULL);
// }

/* Запуск приложения */
int launch_app(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("ru.axel.tl", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate_mainwnd), NULL);
    int status = g_application_run(G_APPLICATION(app), 1, argv); // Передаем только 1 аргумент (название приложение, что-бы не вылетала ошибка "Неизвестный параметр")
    g_object_unref(app);

    return status;
}

