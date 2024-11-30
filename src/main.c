// #include <gtk/gtk.h>
#include <unistd.h> // getopt
#include <ctype.h>

#include "../../lib/logger/bin/logger.h"
#include "headers/app.h"

#define EXIT_SUCCESS 0
#define EXIT_ERROR 1

Logger logger;

// static void activate (GtkApplication *app, gpointer user_data);

int main (int argc, char **argv) {
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

    /* Запуск приложения */
    return launch_app(argc, argv);
}