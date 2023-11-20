#include "longest_streak.h"

unsigned longest_streak(int arr[], unsigned length) {
    if (length == 0) {
        return 0;
    }

    unsigned current_streak = 1;
    unsigned max_streak = 1;

    for (unsigned i = 1; i < length; i++) {
        if (arr[i] == arr[i - 1]) {
            current_streak++;
        } else {
            current_streak = 1;
        }

        if (current_streak > max_streak) {
            max_streak = current_streak;
        }
    }

    return max_streak;
}
