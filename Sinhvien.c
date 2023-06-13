//Program: Lưu trữ, tìm, sửa, xóa, in thông tin sinh viên (Version 2.0)
//Nguyễn Mạnh Khang - T2305E

#include<stdio.h>
#include<string.h>

struct Student
{
    int roll_no, roll_noDaSua;
    char name[30];
    char nameDaSua[30];
    int class, classDasua;
    char section, sectionDasua;
    float marks, marksDasua;
}   student[100];

void studentInfor(int i, int n);
void printStudenin4(int n);
void inforSearching(struct Student student[], int size);
void deleteInfor(struct Student student[], int size);
void fixInfor(struct Student student[], int size);


int main(){
    int choice = 0;
    int flag = 1;
    int i, n;
    
    printf("\nMENU \n1.Search. \n2.Delete. \n3.Edit. \n4.Print \n5.Exit\n");
    printf("\nNhap so luong sinh vien ban muon luu thong tin: ");
    scanf("%d", &n);
    studentInfor(i, n);

    while (flag)
    {
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            inforSearching(student, n);
            break;
        case 2:
            deleteInfor(student, n);
            break;
        case 3:
            fixInfor(student, n);
            break;
        case 4:
            printStudenin4(n);
            break;
        case 5:
            printf("\nKet thuc chuong trinh!");
            flag = 0;
            break;
        default:
            printf("\nInvalid input! Please try again.");
            break;
        }
    }
    return 0;
}

void studentInfor(int i, int n){
    for (i = 0; i < n; i++)
    {
        printf("\nNhap thong tin sinh vien thu %d:", i + 1);
        student[i].roll_no = i + 1;
        printf("\n- ID sinh vien: %d", student[i].roll_no);

        fgets(student[i].name, sizeof(student[i].name), stdin);//Xóa bộ đệm đầu vào trước khi nhập tên

        printf("\n- Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("- Class: ");
        scanf("%d", &student[i].class);

        printf("- Section: ");
        scanf(" %c", &student[i].section);

        printf("- Mark: ");
        scanf("%f", &student[i].marks);
    }
    
}

void printStudenin4(int n){
    for (int i = 0; i < n; i++)
    {   printf("\n%d.\n", student[i].roll_no);
        
        printf("%-10s: %s\n", "- Name", student[i].name);

        printf("%-10s: %d\n", "- Class", student[i].class);

        printf("%-10s: %c\n", "- Section", student[i].section);

        printf("%-10s: %.2f\n", "- Mark", student[i].marks);

    }
    
}

void inforSearching(struct Student student[], int size)
{
    int rollNo; 
    int found = 0;

    while (1)
    {
        printf("\nNhap ID cua sinh vien de tim (Hoac '0' de thoat): ");
        scanf("%d", &rollNo);

        if (rollNo == 0)
        {
            break;
        }
        
        found = 0;

        for (int i = 0; i < size; i++)
        {
            if (student[i].roll_no == rollNo)
            {
                found = 1;
                printf("\nDa tim thay sinh vien!\n");

                printf("\n%d.\n", student[i].roll_no);
        
                printf("%-10s: %s\n", "- Name", student[i].name);

                printf("%-10s: %d\n", "- Class", student[i].class);

                printf("%-10s: %c\n", "- Section", student[i].section);

                printf("%-10s: %.2f\n", "- Mark", student[i].marks);
                break;
            }
        }
        if (!found)
        {
            printf("\nKhong tim thay sinh vien!\n");
        }
    }
}

void deleteInfor(struct Student student[], int size){
    int rollNo; 
    int found = 0;

    while (1)
    {
        printf("\nNhap ID cua sinh vien de xoa (Hoac '0' de thoat): ");
        scanf("%d", &rollNo);

        if (rollNo == 0)
        {
            break;
        }
        
        found = 0;

        for (int i = 0; i < size; i++)
        {
            if (student[i].roll_no == rollNo)
            {
                found = 1;

                student[i].roll_no = 0;

                strcpy(student[i].name, "");

                student[i].class = 0;

                student[i].section = '\0';

                student[i].marks = 0.0;

                printf("\nDa xoa thong tin cua sinh vien co ID: %d\n", rollNo);
                break;
            }
        }
        if (!found)
        {
            printf("\nKhong tim thay sinh vien!\n");
        }
    }
}

void fixInfor(struct Student student[], int size){
    int rollNo;
    int found = 0;

    while (1)
    {
        printf("\nNhap ID cua sinh vien de sua (Hoac '0' de thoat): ");
        scanf("%d", &rollNo);

        if (rollNo == 0)
        {
            break;
        }

        found = 0;

        for (int i = 0; i < size; i++)
        {
            if (student[i].roll_no == rollNo)
            {
                found = 1;
                int choice = 0;
                int flag = 1;

                printf("\n1.ID. \n2.Name. \n3.Class. \n4.Section \n5.Mark\n");

                while (flag)
                {
                    printf("\nNhap lua chon cua ban: ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nNhap ID ban muon sua thanh: ");
                        scanf("%d", &student[i].roll_no);
                        break;
                    case 2:
                        printf("\nNhap ten ban muon sua thanh: ");
                        getchar();  // Đọc ký tự thừa '\n' trong bộ đệm
                        fgets(student[i].name, sizeof(student[i].name), stdin);
                        student[i].name[strcspn(student[i].name, "\n")] = '\0';
                        break;
                    case 3:
                        printf("\nNhap Class ban muon sua thanh: ");
                        scanf("%d", &student[i].class);
                        break;
                    case 4:
                        printf("\nNhap Section ban muon sua thanh: ");
                        scanf(" %c", &student[i].section);
                        break;
                    case 5:
                        printf("\nNhap Mark ban muon sua thanh: ");
                        scanf("%f", &student[i].marks);
                        break;
                    default:
                        printf("\nInvalid input! Please try again.");
                        break;
                    }

                    printf("Ban co muon sua tiep khong? (1: Co / 0: Khong): ");
                    scanf("%d", &flag);
                }

                printf("\nDa sua thanh cong!");
            }
        }

        if (!found)
        {
            printf("\nKhong tim thay sinh vien!\n");
        }
    }
}
