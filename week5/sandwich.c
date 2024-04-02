#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 6  // Define the maximum stack capacity
#define MAXQUEUE 6  // Define the maximum queue capacity

// Array Stack
int stack[MAXSTACK];
int s_top = -1;  // stack top index

// Determine whether stack is empty
int s_stackisEmpty() {
    // stack top -1 代表是空的
    return s_top < 0;
}

// Push data into stack
void s_push(int data) {
    // 將top+1後 賦值
    stack[++s_top] = data;
}

// Pop top data of stack
int s_pop() {
    // return當前物件後 將top - 1
    return stack[s_top--];
}

// Get stack top information
int s_getTop() {
    // return當前物件後
    return stack[s_top];
}

// 刪除所有stack中的資料
void s_clean() {
    // 持續pop值到stack為空
    while (s_stackisEmpty() != 1) {
        s_pop();
    }
}

// Array Queue
int queue[MAXQUEUE];
int q_first = -1;  // The front of queue
int q_last = -1;   // The end of the queue
int q_size = 0;    // queue size

// Determine whether queue is empty
int q_queueisEmpty() {
    // 確認queue的size是否為0
    return q_size == 0;
}

// Put data into the queue (put it from the end)
void q_enqueue(int a) {
    // 賦值到q_list+1
    // enqueue了 q_size - 1
    // enqueue時 如果q_first == -1代表是init, q_first == 0
    queue[++q_last] = a;
    q_size++;

    if (q_first == -1) {
        q_first = 0;
    }
}

// Take out the data in the queue (get it from the front end)
int q_dequeue() {
    // 暫存queue隊首
    // dequeue q_size - 1
    // dequeue時 q_size == 0  代表已經清空, reset q_first & q_last
    int curr = queue[q_first++];
    q_size--;
    if (q_size == 0) {
        q_first = -1;
        q_last = -1;
    }
    return curr;
}

// Get the front-end value
int q_getFirst() {
    // return首端物件後
    return queue[q_first];
}

// Get the value at the end
int q_getLast() {
    // return尾端物件後
    return queue[q_last];
}

// Get queue size
int q_getSize() {
    // return q_size
    return q_size;
}
void q_clean() {
    // 持續dequeue到 q_queueisEmpty = true
    while (q_queueisEmpty() != 1) {
        q_dequeue();
    }
}

void q_reQueueFirstAtRear() {
    // 暫存first值
    // 接下來把所有物件前移1欄
    // 將first值放到last
    int temp = queue[q_first];
    for (int i = q_first; i < q_last; i++) {
        queue[i] = queue[i + 1];
    }
    queue[q_last] = temp;
}

// 清除原先的資料用
void cleanStudentAndSandwich();
// init題目給予的學生和三明治
void initStudentAndSandwich();

int main() {
    // 由於兩個規則都會進行重新排隊 使用一個variable去確定是否至少已經輪轉一輪了
    int reQueueCount = 0;

    // Rule 1:
    printf("1: 遇到喜歡三明治會拿一個後離開，沒遇到會重新排隊\n");
    initStudentAndSandwich();

    // Compare students and sandwiches

    // 當還有三明治而且尚未全部輪轉過一次 進行判斷
    while (s_stackisEmpty() != 1 && reQueueCount < MAXQUEUE) {
        // 代表這是學生喜歡的三明治
        if (s_getTop() == q_getFirst()) {
            // 移除隊首學生以及stack頂部的三明治
            s_pop();
            q_dequeue();
        } else {
            // 將對首輪轉到隊尾重新排隊
            q_reQueueFirstAtRear();
            // 輪轉次數+1
            reQueueCount++;
        }
    }
    printf("有 %d 位學生沒有吃到三明治\n\n", q_getSize());

    // Rule 2:
    printf("2: 遇到喜歡三明治會拿到完後離開，沒遇到會重新排隊\n");
    // 重置data
    initStudentAndSandwich();
    // 重置輪轉count
    reQueueCount = 0;
    // 當還有三明治而且尚未全部輪轉過一次 進行判斷
    while (s_stackisEmpty() != 1 && reQueueCount < MAXQUEUE) {
        // 代表這是學生喜歡的三明治
        if (s_getTop() == q_getFirst()) {
            // 如果還有三明治也是他喜歡的 繼續拿
            while (s_stackisEmpty() != 1 && s_getTop() == q_getFirst()) {
                s_pop();
            }
            // 沒有喜歡的三明治了 學生離開
            q_dequeue();
        } else {
            // 將對首輪轉到隊尾重新排隊
            q_reQueueFirstAtRear();
            // 輪轉次數+1
            reQueueCount++;
        }
    }
    printf("有 %d 位學生沒有吃到三明治\n\n", q_getSize());

    return 0;
}

void cleanStudentAndSandwich() {
    q_clean();
    s_clean();
}

void initStudentAndSandwich() {
    cleanStudentAndSandwich();
    int student[MAXQUEUE] = {1, 1, 1, 0, 0, 1};
    int sandwich[MAXSTACK] = {1, 1, 0, 0, 0, 1};

    // 使用for-loop將資料push&enqueue到我stack和queue
    for (int i = 0; i < MAXQUEUE; i++) {
        s_push(sandwich[i]);
        q_enqueue(student[i]);
    }
}