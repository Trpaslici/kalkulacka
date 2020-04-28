/**
 * \file GUI.c
 *
 * \brief Funkce reagujici na interakci s GUI
 */

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include "knihovna.h"
#include <ctype.h>

#define PLUS 1
#define MINUS 2
#define TIMES 3
#define DIVIDE 4
#define POWER 5
#define ROOT 6
#define COMBINATORY 7

/** vypisuje cisla do labelu */
void write_in_label (char* str1);

/**odesle informace do funkce ke spocitani */
void do_calculations();

double num1;
double num2;
int operator = 0;
GtkWidget	*window1;
GtkWidget	*fixed1;
GtkWidget	*fixed2;
GtkWidget	*button_dot;
GtkWidget	*button_zero;
GtkWidget	*button_eq;
GtkWidget	*button_one;
GtkWidget	*button_two;
GtkWidget	*button_three;
GtkWidget	*button_four;
GtkWidget	*button_five;
GtkWidget	*button_six;
GtkWidget	*button_seven;
GtkWidget	*button_eight;
GtkWidget	*button_nine;
GtkWidget	*button_div;
GtkWidget	*button_times;
GtkWidget	*button_minus;
GtkWidget	*button_plus;
GtkWidget	*button_fact;
GtkWidget	*button_pwr;
GtkWidget	*button_root;
GtkWidget	*button_comb;
GtkWidget	*button_AC;
GtkWidget	*button_sign;
GtkWidget	*label1;
GtkBuilder	*builder;

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk


	builder = gtk_builder_new_from_file ("GUI.glade");

	window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button_dot = GTK_WIDGET(gtk_builder_get_object(builder, "button_dot"));
	button_zero = GTK_WIDGET(gtk_builder_get_object(builder, "button_zero"));
	button_eq = GTK_WIDGET(gtk_builder_get_object(builder, "button_eq"));
	button_one = GTK_WIDGET(gtk_builder_get_object(builder, "button_one"));
	button_two = GTK_WIDGET(gtk_builder_get_object(builder, "button_two"));
	button_three = GTK_WIDGET(gtk_builder_get_object(builder, "button_three"));
	button_four = GTK_WIDGET(gtk_builder_get_object(builder, "button_four"));
	button_five = GTK_WIDGET(gtk_builder_get_object(builder, "button_five"));
	button_six = GTK_WIDGET(gtk_builder_get_object(builder, "button_six"));
	button_seven = GTK_WIDGET(gtk_builder_get_object(builder, "button_seven"));
	button_eight = GTK_WIDGET(gtk_builder_get_object(builder, "button_eight"));
	button_nine = GTK_WIDGET(gtk_builder_get_object(builder, "button_nine"));
	button_div = GTK_WIDGET(gtk_builder_get_object(builder, "button_div"));
	button_times = GTK_WIDGET(gtk_builder_get_object(builder, "button_times"));
	button_minus = GTK_WIDGET(gtk_builder_get_object(builder, "button_minus"));
	button_plus = GTK_WIDGET(gtk_builder_get_object(builder, "button_plus"));
	button_fact = GTK_WIDGET(gtk_builder_get_object(builder, "button_pwr"));
	button_pwr = GTK_WIDGET(gtk_builder_get_object(builder, "button_fact"));
	button_root = GTK_WIDGET(gtk_builder_get_object(builder, "button_root"));
	button_comb = GTK_WIDGET(gtk_builder_get_object(builder, "button_comb"));
	button_AC = GTK_WIDGET(gtk_builder_get_object(builder, "button_AC"));
	button_AC = GTK_WIDGET(gtk_builder_get_object(builder, "button_sign"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));

    GdkColor color;
    color.red = 0xcccc;
    color.green = 0xcccc;
    color.blue = 0xd900;
    gtk_widget_modify_bg(GTK_WIDGET(window1), GTK_STATE_NORMAL, &color);

	gtk_widget_show(window1);

	gtk_main();

	return EXIT_SUCCESS;
	}

/**
 * \brief stisknuti tlacitka '.'
 */
void	on_button_dot_clicked (GtkButton *b) {
	write_in_label(".");
	}

/**
 * \brief stisknuti tlacitka '0'
 */
void	on_button_zero_clicked (GtkButton *b) {
	write_in_label("0");
	}

/**
 * \brief stisknuti tlacitka '='
 */
void	on_button_eq_clicked (GtkButton *b) {

	}

/**
 * \brief stisknuti tlacitka '1'
 */
void	on_button_one_clicked (GtkButton *b) {
	write_in_label("1");
	}

/**
 * \brief stisknuti tlacitka '2'
 */
void	on_button_two_clicked (GtkButton *b) {
	write_in_label("2");
	}

/**
 * \brief stisknuti tlacitka '3'
 */
void	on_button_three_clicked (GtkButton *b) {
	write_in_label("3");
	}

/**
 * \brief stisknuti tlacitka '4'
 */
void	on_button_four_clicked (GtkButton *b) {
	write_in_label("4");
	}

/**
 * \brief stisknuti tlacitka '5'
 */
void	on_button_five_clicked (GtkButton *b) {
	write_in_label("5");
	}

/**
 * \brief stisknuti tlacitka '6'
 */
void	on_button_six_clicked (GtkButton *b) {
	write_in_label("6");
	}

/**
 * \brief stisknuti tlacitka '7'
 */
void	on_button_seven_clicked (GtkButton *b) {
	write_in_label("7");
	}

/**
 * \brief stisknuti tlacitka '8'
 */
void	on_button_eight_clicked (GtkButton *b) {
	write_in_label("8");
	}

/**
 * \brief stisknuti tlacitka '9'
 */
void	on_button_nine_clicked (GtkButton *b) {
	write_in_label("9");
	}

/**
 * \brief stisknuti tlacitka deleno
 */
void	on_button_div_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = DIVIDE;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka krat
 */
void	on_button_times_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = TIMES;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka minus
 */
void	on_button_minus_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = MINUS;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka plus
 */
void	on_button_plus_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = PLUS;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka faktorial
 */
void	on_button_fact_clicked (GtkButton *b) {
	num1 = strtod(gtk_label_get_text(label1));
	factorial(num1);
	write_in_label();				//TODO
	num1 = 0;
	num2 = 0;
	operator = 0;
	}

/**
 * \brief stisknuti tlacitka mocniny
 */
void	on_button_pwr_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = POWER;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka odmocniny
 */
void	on_button_root_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = ROOT;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka kombinacniho cisla
 */
void	on_button_comb_clicked (GtkButton *b) {
	if (operator == 0) {
		num1 = strtod(gtk_label_get_text(label1));
		operator = COMBINATORY;
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(label1));
		do_calculations();
	}
}

/**
 * \brief stisknuti tlacitka "AC"
 */
void	on_button_AC_clicked (GtkButton *b) {
	num1 = 0;
	num2 = 0;
	operator = 0;
	gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "0");
}

/**
 * \brief stisknuti tlacitka "+/-"
 */
void	on_button_sign_clicked (GtkButton *b) {
	num1 = strtod(gtk_label_get_text(label1));
	invert(num1);
	write_in_label();			//TODO
}

/**
 * \brief vypisuje cisla do labelu
 */
void write_in_label (char* str1) {
	const gchar* str2 = gtk_label_get_text(label1);
	if (g_strstr(str2, "0") == NULL) {
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) str1);
	}
	else {
		strcat(str2, str1);
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) str2);
	}
}

/**
 * \brief vypocita vysledek na zaklade zvoleneho operatoru
 */
void do_calculations() {
	double result;
	switch (operator) {
		case (PLUS):
			result = add(num1, num2);
			break;
		case (MINUS):
			result = sub(num1, num2);
			break;
		case (TIMES):
			result = mul(num1, num2);
			break;
		case (DIVIDE):
			result = divid(num1, num2);
			break;
		case (POWER):
			result = pow(num1, num2);
			break;
		case (ROOT):
			result = rad(num1, num2);
			break;
		case (COMBINATORY):
			result = komb(num1, num2);
			break;
	}

	operator = 0;
	num1 = 0;
	num2 = 0;

	write_in_label();				//TODO
}

/*** Konec souboru GUI.c ***/
