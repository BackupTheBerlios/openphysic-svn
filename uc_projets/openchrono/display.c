void display(void)
{
    // clear screen
    // TO DO

    // line 1

    print_time(&current_time); // ZONE 1

    printf(" ");

    print_time(&best_time); // ZONE 2


    printf("\n");
    // line 2

    print_time(&last_time); // ZONE 3

    printf(" ");

    // ZONE 4
    if( compare_time(&current_time,&last_time) == 0 )
    {
        printf("LST=");
    }
    if( compare_time(&current_time,&last_time) == 1 )
    {
        printf("LST-");
    }
    if( compare_time(&current_time,&last_time) == 2 )
    {
        printf("LST-");
    }

    if( compare_time(&current_time,&best_time) == 0 )
    {
        printf("BST=");
    }
    if( compare_time(&current_time,&best_time) == 1 )
    {
        printf("BST-");
    }
    if( compare_time(&current_time,&best_time) == 2 )
    {
        printf("BST+");
    }

}
