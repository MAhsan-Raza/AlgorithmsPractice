#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {

    printf("%s:\n", t.name);
    for(int i=0;i<t.offices_count;i++)
    {
        printf("\t%d:\n", i);
        for(int j=0;j<t.offices[i].packages_count;j++)
        {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) 
{
    post_office* src_ofc 
        = source->offices + source_office_index;
    
    post_office* dst_ofc 
        = target->offices + target_office_index;
    
    package* pkgs = (package*)malloc(
        src_ofc->packages_count * sizeof(package));
    
    memcpy(pkgs, src_ofc->packages,
        src_ofc->packages_count * sizeof(package));
    int src_pkg_cnt = src_ofc->packages_count;

    free(src_ofc->packages);
    src_ofc->packages = NULL;
    src_ofc->packages_count = 0;

    int acpt_pkg_count = 0;
    for(int i=0;i<src_pkg_cnt;i++)
    {
        if(pkgs[i].weight >= dst_ofc->min_weight
            && pkgs[i].weight <= dst_ofc->max_weight)
        {
            ++acpt_pkg_count;
        }
    }

    int rjctd_pkg_count = src_pkg_cnt - acpt_pkg_count;
    
    src_ofc->packages = (package*)
        malloc(rjctd_pkg_count * sizeof(package));
    
    dst_ofc->packages = (package*) realloc(dst_ofc->packages, 
        (dst_ofc->packages_count + acpt_pkg_count)
         * sizeof(package));
    
    for(int i=0;i<src_pkg_cnt;i++)
    {
        if(pkgs[i].weight >= dst_ofc->min_weight
            && pkgs[i].weight <= dst_ofc->max_weight)
        {
            *(dst_ofc->packages + dst_ofc->packages_count++) = pkgs[i];
        }
        else 
        {
            *(src_ofc->packages + src_ofc->packages_count++) = pkgs[i];
        }
    }

    free(pkgs);
}

int getPackgs(town t)
{
    int sum = 0;

    for(int i=0;i<t.offices_count;i++)
        sum+=t.offices[i].packages_count;
    return sum;
}

town town_with_most_packages(town* towns, int towns_count) {
    
    town maxT;
    for(int i=0;i<towns_count;i++)
    {
        if(i==0)
        {
            maxT = towns[i];
        }
        else 
        {
            if(getPackgs(maxT) < getPackgs(towns[i]))
                maxT = towns[i];
        }
    }

    return maxT;
}

town* find_town(town* towns, int towns_count, char* name) 
{
    //return towns;
    for(int i=0;i<towns_count;i++)
    {
        if(strcmp(towns[i].name, name) == 0)
            return towns + i;
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}

