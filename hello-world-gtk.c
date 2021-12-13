#include <gtk/gtk.h>
#include <wiringPi.h>
#include <stdio.h>

GtkWidget *txt;

void end_program(GtkWidget *wid, gpointer ptr)
{
  gtk_main_quit();
}

void toggle1(GtkWidget *wid, gpointer ptr)
{
  gtk_label_set_text(GTK_LABEL(ptr), "gpio 17 on");
  while (gtk_events_pending())
    gtk_main_iteration();
  digitalWrite(17, HIGH); // On
  delay(2000);

  gtk_label_set_text(GTK_LABEL(ptr), "gpio 17 off");
  while (gtk_events_pending())
    gtk_main_iteration();
  digitalWrite(17, LOW); // Off
  delay(2000);
  gtk_label_set_text(GTK_LABEL(ptr), "GTK input/output app");
}

void toggle2(GtkWidget *wid, gpointer ptr)
{
  gtk_label_set_text(GTK_LABEL(ptr), "gpio 27 on");
  while (gtk_events_pending())
    gtk_main_iteration();
  digitalWrite(27, HIGH); // On
  delay(2000);

  gtk_label_set_text(GTK_LABEL(ptr), "gpio 27 off");
  while (gtk_events_pending())
    gtk_main_iteration();
  digitalWrite(27, LOW); // Off
  delay(2000);
  gtk_label_set_text(GTK_LABEL(ptr), "GTK input/output app");
}

void toggle3(GtkWidget *wid, gpointer ptr)
{

  if (digitalRead(10) == HIGH)
  {
    gtk_label_set_text(GTK_LABEL(ptr), "button pressed (gpio 10)");
  }
  else if (digitalRead(10) == LOW)
  {
    gtk_label_set_text(GTK_LABEL(ptr), "button not pressed (gpio 10)");
  }
}

void toggle4(GtkWidget *wid, gpointer ptr)
{

  if (digitalRead(22) == HIGH)
  {
    gtk_label_set_text(GTK_LABEL(ptr), "button pressed (gpio 22)");
  }
  else if (digitalRead(22) == LOW)
  {
    gtk_label_set_text(GTK_LABEL(ptr), "button not pressed (gpio 22)");
  }
}

int main(int argc, char *argv[])
{

  wiringPiSetupGpio();
  pinMode(27, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(10, INPUT);
  pinMode(22, INPUT);

  gtk_init(&argc, &argv);
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);   //Window
  GtkWidget *btn = gtk_button_new_with_label("Exit");     //button
  GtkWidget *lbl = gtk_label_new("GTK input/output app"); //label
  GtkWidget *lbl2 = gtk_label_new("choose pgio (uitbreiding):");        //label
  GtkWidget *input1 = gtk_label_new("button input1");     //label
  GtkWidget *input2 = gtk_label_new("button input2");     //label
  GtkWidget *inputtitle = gtk_label_new("input status:"); //label

  GtkWidget *tbl = gtk_table_new(4, 4, TRUE);            //tabel //0-4
  GtkWidget *btn2 = gtk_button_new_with_label("17");     //Count button
  GtkWidget *btn3 = gtk_button_new_with_label("27");     //Count button
  GtkWidget *btn4 = gtk_button_new_with_label("toggle"); //Count button
  GtkWidget *btn5 = gtk_button_new_with_label("check inputs"); //Count button
  GtkWidget *input = gtk_entry_new();
  //ComboBox (uitbreiding)
  //events
  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(btn2, "clicked", G_CALLBACK(toggle1), lbl);
  g_signal_connect(btn3, "clicked", G_CALLBACK(toggle2), lbl);
  g_signal_connect(btn5, "clicked", G_CALLBACK(toggle3), input1);
  g_signal_connect(btn5, "clicked", G_CALLBACK(toggle4), input2);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

  //widgets toevoegen aan tabel
  gtk_table_attach_defaults(GTK_TABLE(tbl), lbl, 1, 11, 0, 1); 
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn2, 1, 5, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn3, 5, 10, 1, 2);

  gtk_table_attach_defaults(GTK_TABLE(tbl), lbl2, 1, 11, 2, 3);
  gtk_table_attach_defaults(GTK_TABLE(tbl), input, 1, 7, 3, 4);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn4, 7, 10, 3, 4);

  gtk_table_attach_defaults(GTK_TABLE(tbl), btn5, 3, 5, 5, 6);
  gtk_table_attach_defaults(GTK_TABLE(tbl), inputtitle, 1, 11, 5, 6);
  gtk_table_attach_defaults(GTK_TABLE(tbl), input1, 0, 5, 6, 7);
  gtk_table_attach_defaults(GTK_TABLE(tbl), input2, 5, 10, 6, 7);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 10, 11, 8, 9);

  gtk_container_add(GTK_CONTAINER(win), tbl);

  gtk_widget_show_all(win);

  gtk_main();
}
