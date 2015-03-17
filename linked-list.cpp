#include <stdio.h>
#include <stdlib.h>

struct liste
{
    int no;
    char isim[20];
    struct liste *sonraki;
};
typedef struct liste isimler;

isimler *liste_olustur();
void ekle(isimler **head);
void goster(isimler *head);
void delete_node(isimler **head);
int main()
{
    int *p;
    p=liste_olustur();
    goster(p);
    ekle(&p);
    goster(p);
    delete_node(&p);
    goster(p);
    return 0;
}
isimler *liste_olustur(){
   int k, n;
   isimler *p, *head;
   printf("Kac eleman girilecek\n");
   scanf("%d", &n);
   for(k=0;k<n;k++)
   {
        if(k==0)
        {
            head = (isimler *) malloc(sizeof(isimler));
            p = head;
        }
        else
        {
            p -> sonraki = (isimler *)malloc(sizeof(isimler));
            p = p->sonraki;
        }
        printf("\nOgrenci No: ");
        scanf("%d", &p->no);
        printf("Isim: ");
        scanf("%s", p->isim);

   }
   p->sonraki = NULL;
   return(head);
}
void goster(isimler *head)
    {
        int count =1;
        isimler *p;
        p=head;
        while(p!=NULL)
        {
            printf("\nNone %d: %d %s ", count, p->no, p->isim);
            count++;
            p=p->sonraki;
        }
        printf("\n");
    }
void ekle(isimler **head)
    {
        int k = 0, rno;
        isimler *p, *q, *new_;
        new_=(isimler *)malloc(sizeof(isimler));
        printf("\nVeri ekleme: No Ve Isim\n");
        scanf("%d %s", &new_->no, new_->isim);
        printf("\nHangi no dan once");
        scanf("%d", &rno);
        p = *head;

        if(p -> no == rno)
        {
            new_-> sonraki = p;
            *head = new_;
        }
        else
        {
            while((p != NULL) && (p->isim != rno))
            {
                q = p;
                p = p -> sonraki;
            }
            if(p == NULL)
            {
                q->sonraki = new_;
                new_->sonraki = NULL;
            }
            else if(p->isim==rno)
            {
                q->sonraki = new_;
                new_->sonraki = p;
            }
        }
    }
void delete_node(isimler **head)
    {
        int rno;
        isimler *p, *q;
        printf("\nSilinecek no'yu secin\n");
        scanf("%d",&rno);
        p = *head;
        if(p -> no == rno)
        {
            *head = p->sonraki;
            free(p);
        }
        else
        {
            while((p!=NULL) && (p->no != rno))
            {
                q = p;
                p = p->sonraki;
            }
            if(p==NULL)
                printf("\nSilinecek oge bulunamadi\n");
            else if(p->no == rno)
            {
                q-> sonraki = p-> sonraki;
                free(p);
            }
        }
    }

