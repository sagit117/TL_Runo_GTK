#include <gtk/gtk.h>
#include <unistd.h> // getopt
#include <ctype.h>

#include "../../lib/logger/bin/logger.h"

#define EXIT_SUCCESS 0
#define EXIT_ERROR 1

Logger logger;

static void activate (GtkApplication *app, gpointer user_data);

int main (int argc, char **argv) {
    // #ifdef GTK_SRCDIR
    //     g_chdir (GTK_SRCDIR);
    // #endif

    /* Активация логера */
    logger.max_size = 1024;
    logger.out = stdout;
    logger.level = INFO;

    /* Разбор аргументов командной строки */
    char *file_cfg_path;
    extern char *optarg;
    extern int opterr;
    extern int optopt;
    int res = 0;
    opterr = 0;

    while ((res = getopt(argc, argv, "hc:d")) != -1) {
		switch (res) {
            case 'h': 
                printf("Параметры приложения:\
                    \n\t-c: параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg\
                    \n\t-d: включает дополнительное логирование на уровне BEBUG\
                    \n"); 
                return EXIT_SUCCESS; 
            case 'c': 
                file_cfg_path = optarg; 
                break;
            case 'd':
                logger.level = DEBUG;
                break;
            case '?': 
                if (optopt == 'c') {
                    fprintf(stderr, "Параметер -%c должен иметь аргумент.\n", optopt);
                } else if (isprint(optopt)) {
                    fprintf(stderr, "Неизвестный параметр`-%c'.\n", optopt);
                } else {
                    fprintf(stderr, "Неизвестный символ в параметре `\\x%x'.\n", optopt);
                }
            default: break;
		} 
	}

    /* Запуск главного окна */
    GtkApplication *app = gtk_application_new("ru.axel.tl", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), 1, argv); // Передаем только 1 аргумент (название приложение, что-бы не вылетала ошибка "Неизвестный параметр")

    g_object_unref(app);

    return status;
}

static void quit_activated (GSimpleAction *action, GVariant *parameter, gpointer app) {
  g_application_quit (G_APPLICATION (app));
}

static GActionEntry app_entries[] = {
//   { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};

/* Метод активации главного окна */
static void activate (GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "./src/ui/mainwnd.ui", NULL);

    GObject *window = gtk_builder_get_object(builder, "window");
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
    // gtk_window_maximize(GTK_WINDOW(window));

    g_object_unref (builder);
}