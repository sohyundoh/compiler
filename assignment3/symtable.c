#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"


int hashcode; //hash code of identifier
int sameid;  //first index of identifier
int stindex = 0;
int overflow = 0;
int found; //for the previous occurrence of an identifie
int nextid = 0;
int nextfree = 0;
int i = 0;


void ReadID() {// 한 글자씩 ST에 저장
    nextid = nextfree;

    for (i = 0; i < yyleng; i++) {
        // 오버플로우 체크
        if (nextfree >= STsize) {
            overflow = 1;
            return;
        }

        ST[nextfree] = yytext[i];
        nextfree++;
    }

    // identifier 마지막에 널문자 추가
    if (nextfree >= STsize)
        overflow = 1;
    else {
        ST[nextfree] = '\0';
    }
}

/* deleteID
   :ST에 받아두었던 id 삭제*/
void deleteID() {
    nextfree = nextid;
}

/* insertID
   :ST에 받아두었던 id 저장 확정 */
void insertID() {
    stindex = nextid;
}

/* ComputeHS
   :명칭의 해쉬값 계산*/
int ComputeHS(int nid, int nfree)
{
    int askiisum = 0; //identifier의 아스키코드 총합 변수 선언
    for (int i = nid; i < nfree - 1; i++) {
        askiisum += (int)ST[i];
    }
    /* 인덱스 nid부터 nfree 까지에 해당하는 ST의 값을 읽어와서 더해준 후,
    HT의 크기로 나누고, +1 한 값이 hashcode   */
    hashcode = askiisum % HTsize + 1;
    return hashcode;
}

/* LookupHS
   :동일한 명칭이 존재 여부와 인덱스 파악 */
int LookupHS(int nid, int hscode) {

    int i, j;
    HTpointer ptr = NULL;
    found = FALSE; // 중복 체크하는 불린
    if (HT[hscode] != NULL) {
        ptr = HT[hscode];
        while (ptr != NULL && found == FALSE) {
            found = TRUE;
            j = ptr->index;
            i = nid;
            sameid = i;
            while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) { //i는 새 명칭, j는 이미 입력된 명칭의 위치
                if (ST[i] != ST[j]) { //하나씩 비교하면서 달라지는 문자가 나오면 비교 종료
                    found = FALSE;
                    return -1; //둘이 다른 명칭
                }
                else { //달라지는 문자가 나올 때까지 비교
                    i++;
                    j++;
                }
            }
            if (ptr->next != NULL)
                ptr = ptr->next; //HT[hscode]의 다음 포인터로
        }
        return ptr = ptr->index;
    }

}

/* ADDHT
   :해시 테이블에 저장*/
void ADDHT(int hscode) {
    HTpointer pit;

    pit = (HTpointer)malloc(sizeof(pit));
    
    if(pit)  pit->index = nextid;
    if(pit != NULL) pit->index = nextid;
    
    if (pit)  pit->next = HT[hscode];
    if (pit != NULL) pit->next = HT[hscode];

    HT[hscode] = pit;
    //HT에 추가되지 않은 identifier인 경우
     //index는 ST의 index, next는 null인 새로운 HTEntry 생성
     //기존 HT에 추가
}

/* SymbolTable
   :새로운 명칭이 기존에 존재하지 않으면 해쉬테이블에 저장 */
void SymbolTable()
{
    //int i;
    int ptr_idx;
    ReadID();

    if (overflow) {
        return;
    }

    nextfree++;

    hashcode = ComputeHS(nextid, nextfree);
    ptr_idx = LookupHS(nextid, hashcode); //중복인 명칭과 동일한 기존 명칭의 ST 위치. 존재하면 found는 true

    if (!found) { //found 가 FALSE일 때 (두 명칭이 다를 때)
        ADDHT(hashcode);
        insertID();
    }
    else {
        stindex = ptr_idx;
        deleteID();
    }
}