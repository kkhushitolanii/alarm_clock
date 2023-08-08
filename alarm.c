#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main() {
    time_t rawtime;
    struct tm *timeinfo;
    int alarm_hour, alarm_minute;
    printf("Simple Alarm Clock\n");
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current time: %02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min);
    printf("Set the alarm time (hour minute): ");
    scanf("%d %d", &alarm_hour, &alarm_minute);
    if (alarm_hour < 0 || alarm_hour > 23 || alarm_minute < 0 || alarm_minute > 59) {
        printf("Invalid alarm time. Please enter a valid time.\n");
        return 1;
    }
    printf("Alarm set for: %02d:%02d\n", alarm_hour, alarm_minute);
    int alarm_seconds = alarm_hour * 3600 + alarm_minute * 60;
    int current_seconds = timeinfo->tm_hour * 3600 + timeinfo->tm_min * 60 + timeinfo->tm_sec;
    int time_until_alarm = alarm_seconds - current_seconds;
    if (time_until_alarm <= 0) {
        printf("Alarm time has already passed.\n");
        return 0;
    }
    printf("Sleeping until the alarm...\n");
    sleep(time_until_alarm);
    printf("\nALARM! ALARM! ALARM!\n");
    return 0; 
}