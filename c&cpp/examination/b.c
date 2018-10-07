#include<stdio.h>
#include<stdlib.h>
#define NAME_LEN 100
#define SEX_LEN 6
typedef struct {
int id;//身份证号码
    char lastname[NAME_LEN+1];//姓
    char firstname[NAME_LEN+1];//名
    char sex[SEX_LEN];//性别
    double ability;
} TeamMember;

void showCaptain(TeamMember team[], int n);
int main()
{
    TeamMember *team;
    int n;
    int i;

    scanf("%d",&n);
    team = (TeamMember *)malloc(n*sizeof(TeamMember));
    for(i=0;i<n;i++)
    {
        scanf("%d %s %s %s %lf",&team[i].id,team[i].lastname, team[i].firstname, team[i].sex, &team[i]. ability);
    }

    showCaptain(team, n);

    return 0;
}

void showCaptain(TeamMember team[], int n){
    TeamMember cap;
    cap.ability = -1;
    for(int i = 0; i < n; i++){
        printf("%f\n", team[i].ability);
        if( cap.ability < team[i].ability){
            cap = team[i];
        }
    }
    printf("%d %s %s %s %lf", cap.id, cap.lastname, cap.firstname, cap.sex, cap.ability);
}