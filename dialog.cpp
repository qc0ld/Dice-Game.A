#include "dialog.h"
#include "handle.h"

namespace Dialog {
    void throw_dice(Dice_vector &vector) {
        if (vector.get_amount() == 0) {
            cout << "Nothing to throw" << endl;
        } else {
            vector.throw_dice();
            cout << "Dices were thrown" << endl;
        }
        display_dice(vector);
    }

    void insert_dice(Dice_vector &vector) {
            vector.insert_dice();
        display_dice(vector);
    }

    void remove_dice(Dice_vector &vector) {
        int number = read_int("number");
        if (number < 1 || number > vector.get_amount()) {
            cout << "Dice not found" << endl;
            return;
        }
        vector.remove_dice(number);
        cout << "Dice was removed" << endl;
        display_dice(vector);
    }

    void remove_all_dices(Dice_vector &vector) {
        vector.remove_all_dices();
        cout << "All dices were removed" << endl;
    }

    void display_dice(Dice_vector &vector) {
        if (vector.get_amount() == 0) {
            cout << "There is no dices" << endl;
            return;
        }
        for (int i = 0; i < vector.get_max_size(); ++i) {
            if (vector.get_value(i) != 0) {
                cout << i + 1 << ": " << "[" << vector.get_value(i) << "]" << endl;
            }
        }
    }

    void find_dice(Dice_vector &vector) {
        int number = read_int("number");
        if (number < 1 || number > vector.get_amount()) {
            cout << "Dice not found" << endl;
        } else {
            cout << "Dice #" << number << ": " << "[" << vector.find_dice(number) << "]" << endl;
        }
    }

    void sum_all_dices(Dice_vector &vector) {
        cout << "Sum of all dices: " << vector.sum_all_dices() << endl;
    }

    void check_for_coincidences(Dice_vector &vector) {
        int check = vector.check_for_coincidences();
        if (check == 1 || vector.get_amount() == 0 || vector.get_amount() == 1) {
            cout << "Coincidences not found" << endl;
        } else {
            cout << "There is at least one coincidence" << endl;
        }
    }
}