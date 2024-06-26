#include "proj3_2018_schedList.h"

proj3_2018_schedList::proj3_2018_schedList(){
    numSchedules = 0;
    for(int i = 0; i < MAX_SCHEDULES; i++){
        proj3_2018_schedule emptySchedule;
        schedules[i] = emptySchedule;
    }
}

int proj3_2018_schedList::getNumSchedules(){return numSchedules;}

proj3_2018_schedule proj3_2018_schedList::getSchedule(int idx){
    if(idx < 0 || idx > MAX_SCHEDULES){
        proj3_2018_schedule emptySchedule;
        return emptySchedule;
    }
    else{
        return schedules[idx];
    }
}

proj3_2018_schedule proj3_2018_schedList::getSchedule(string sId){
    for(int i = 0; i < numSchedules; i++){
        if(schedules[i].stuId == sId){
            return schedules[i];
        }
    }
    proj3_2018_schedule emptySchedule;
    return emptySchedule;
}

void proj3_2018_schedList::addSchedule(proj3_2018_schedule s){
    for(int i = 0; i < numSchedules; i++){
        if(schedules[i].stuId == s.stuId){
            schedules[i] = s;
            return;
        }
    }
    // not found, add schedule
    if(numSchedules < MAX_SCHEDULES){
        schedules[numSchedules] = s;
        numSchedules++;
    }
    else{
        cout << "Unable to add schedule. Schedule List is full!";
    }
}

void proj3_2018_schedList::print(){
    cout << "=============== ALL SCHEDULES (" << numSchedules << ") ================\n"
         << "STUID #C COURSE IDS\n"
         << "----- -- ----------------------------------\n";
    for(int i=0; i < numSchedules; i++){
        schedules[i].print();
    }
    cout << endl;
}

void proj3_2018_schedList::read(){
    ifstream f;

    string filename = "schedList.txt";

    f.open(filename);

    if(f.fail()){
        cout << "Unable to open "<< filename << endl;
        return;
    }
    string courseID;
    f >> numSchedules;
    for(int i = 0; i < numSchedules; i++){
        f >> schedules[i].stuId >> schedules[i].numRegCourses;
        for(int j = 0; j < schedules[i].numRegCourses; j++){
            f >> courseID;
            schedules[i].regCourses[j].setId(courseID);
        }
    }
    f.close();
}

void proj3_2018_schedList::write(){
    ofstream f;

    string filename = "schedList_1.txt";

    f.open(filename);

    if(f.fail()){
        cout << "Unable to open " << filename << endl;
    }

    f << numSchedules << endl;
    for(int i = 0; i < numSchedules; i++){
        f << schedules[i].stuId << " " << schedules[i].numRegCourses << " ";
        for(int j = 0; j < schedules[i].numRegCourses; j++){
            f << schedules[i].regCourses[j].getId() << " ";
        }
        if(i != numSchedules -1){
            f << endl;
        }
    }
}
