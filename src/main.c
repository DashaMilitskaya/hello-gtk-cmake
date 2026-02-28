#include <gtk/gtk.h>
#include "hello.h"
static void
print_hello(GtkWidget *widget, gpointer data)
{
  g_print("Hello World from GTK + CMake!\n");
}

static void
activate(GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;

  // Создаём окно
  window = gtk_application_window_new(app);
  // TO_DO: free memory from helloGet when window destroy
  char *MyTitle = helloGet();
  gtk_window_set_title(GTK_WINDOW(window), MyTitle);
  free(MyTitle);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  // Вертикальный бокс для центрирования
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_margin_top(box, 20);
  gtk_widget_set_margin_bottom(box, 20);

  // Кнопка
  button = gtk_button_new_with_label("Нажми меня !!!");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  g_signal_connect_swapped(button, "clicked",
                           G_CALLBACK(gtk_window_destroy), window);

  // Добавляем кнопку в бокс
  gtk_box_append(GTK_BOX(box), button);

  // Устанавливаем бокс как дочерний элемент окна
  gtk_window_set_child(GTK_WINDOW(window), box);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.example.hello-cmake",
                            G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}