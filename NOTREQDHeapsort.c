#include <stdio.h>



void print_array(int list[],int length,char *print_string){
    printf("%s\n", print_string);
    for (int i = 0; i < length ; i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}


void max_heap(int list[], int pos, int list_length)
{
    int left_child = pos*2 + 1;
    int right_child = pos*2 + 2;
    int tmp;
    
    if (left_child > list_length-1)
        return;
    tmp = left_child;
    if (list[left_child] < list[right_child])
        tmp = right_child;
    if (list[pos] < list[tmp])
    {
       // print_array(list, 12, "build max heap ing-:");
        int t = list[pos];
        list[pos] = list[tmp];
        list[tmp] = t;
      //  print_array(list, 12, "build max heap ing:");
        max_heap(list, tmp, list_length);
        
    }
}


void build_max_heap(int list[], int list_length)
{
    for (int i = list_length/2 - 1; i>=0; i--)
    {
        max_heap(list, i, list_length);
    }
    print_array(list, list_length, "build max heap finished:");
}


void heap_sort(int list[], int list_length)
{
    int heap_size = list_length;
    build_max_heap(list, heap_size);
    
    for (int i = heap_size - 1; i > 0; i--)
    {
        int temp = list[0];
        list[0] = list[i];
        list[i] = temp;  
        heap_size = i-1;
        max_heap(list, 0, heap_size);
    }
     
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int length = 12;
    int list[] = {5,7,2,20,9,11,16,25,18,14,13,21};
    print_array(list,length,"before heap_sort:");
    heap_sort(list,length);
    print_array(list,length,"after heap_sort:");
    return 0;

}