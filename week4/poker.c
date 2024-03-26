#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 建立名為 Cards 的 Struct
typedef struct {
    int number;
    char suit;
} Cards;

// 定義function
// genDeck: 產生一副撲克牌
// genRandomCards: 從牌組中抽取三張不重複的卡
// shoot: 執行射龍門遊戲
void genDeck(Cards* deck, int deckSize);
void genRandomCards(Cards** c1, Cards** c2, Cards** c3, Cards* deck);
int shoot(Cards* c1, Cards* c2, Cards* c3);

int main() {
    Cards cards[52];
    // 產生隨機數使用的seed,
    srand(time(0));
    // 1. 建立牌堆-----------------------------------------------------------------------------
    printf("第一題：產生牌堆\n");
    genDeck(cards, 52);

    // 2. 射龍門------------------------------------------------------------------------------
    printf("\n\n第二題：射龍門\n");
    printf("\t第一張\t第二張\t第三張\n");

    for (int i = 0; i < 5; i++) {
        // 建立三個遊戲卡的空指針
        Cards* c1 = NULL;
        Cards* c2 = NULL;
        Cards* c3 = NULL;

        printf("%d.", i);
        genRandomCards(&c1, &c2, &c3, cards);
        shoot(c1, c2, c3);
    }

    printf("\n\n");
    return 0;
}

void genDeck(Cards* deck, int deckSize) {
    // 四種花色
    char suits[] = {'S', 'H', 'D', 'C'};
    // 使用for-loop創造52張卡片
    for (int i = 0; i < deckSize; i++) {
        // 0-12為第一個花色, 13-25為第二個 ... 取i/13的商來決定撲克牌的花色
        int suitCount = i / 13;
        // 取i/13的餘數加上1即可得到1~13的點數
        int currNumber = i % 13 + 1;
        // 使用i找到目標的卡賦值
        Cards* curr = deck + i;
        curr->number = currNumber;
        // 使用i/13的商找到當前的花色
        curr->suit = *(suits + suitCount);
        printf("\t%c%d", *(suits + suitCount), currNumber);
        if (currNumber == 13)
            printf("\n");
    }
};

void genRandomCards(Cards** c1, Cards** c2, Cards** c3, Cards* deck) {
    while (*c1 == NULL) {
        // 產出範圍0~51的隨機數
        int num1 = rand() % 52;
        int num2 = rand() % 52;
        int num3 = rand() % 52;
        // 檢查是否有重複
        if (num1 != num2 && num2 != num3 && num1 != num3) {
            // 使用傳入的pointer的pointer改變原先的pointer
            *c1 = deck + num1;
            *c2 = deck + num2;
            *c3 = deck + num3;
        }
    }
}

int shoot(Cards* c1, Cards* c2, Cards* c3) {
    printf("\t%c%d\t%c%d\t%c%d\n", c1->suit, c1->number, c2->suit, c2->number, c3->suit, c3->number);
    // 86-93行： 為了方便計算 將傳入的前兩張卡分配給t,b 代表上以及下範圍
    Cards* t = c1;
    Cards* b = c2;
    Cards* shooter = c3;
    if (t->number < b->number) {
        Cards* temp = t;
        t = b;
        b = temp;
    }
    if ((shooter->number == t->number) || (shooter->number == b->number)) {
        // 如果撞柱 將兩者的花色進行比較並顯示結果(未定義t,b同數的狀況)
        // 判斷花色的方法使用char本身代表的acsii值
        Cards* opponent = (shooter->number == t->number) ? t : b;
        printf("\t撞柱-%s", (shooter->suit < opponent->suit) ? "失敗" : "獲勝");
    } else if (shooter->number > t->number || shooter->number < b->number) {
        // 由於已經定義好t為上界 b為下界，當數字大於上界並小於下界才算成功
        printf("\t失敗");
    } else {
        printf("\t獲勝");
    }
    printf("\n");
    return 0;
}
