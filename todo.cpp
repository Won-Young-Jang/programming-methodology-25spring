#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for(int i = 0; i < MAX_TASKS; i++){
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i = 0; i < MAX_TASKS; i++){
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    dest = new char[string_length(src) + 1];
    for(int i = 0; i <= string_length(src); i++){
        dest[i] = src[i];
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size == MAX_TASKS) throw std::overflow_error("Todo list is full");
    tasks[size] = new char[string_length(task) + 1];
    for(int i = 0; i <= string_length(task); i++){
        tasks[size][i] = task[i];
    }
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(index >= size || index < 0) throw std::invalid_argument("Invalid index");
    for(int i = index; i < size - 1; i++){
        delete[] tasks[i];
        string_copy(tasks[i], tasks[i + 1]);
    }
    delete[] tasks[size - 1];
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;

    const char** result = new const char*[size+1];
    for (int i = 0; i < size; i++){
        result[i] = tasks[i];
    }
    return result;
}