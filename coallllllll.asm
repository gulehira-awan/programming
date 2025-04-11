.model small
.stack 100h

.data
    
    input_password db 'Please enter your password: $'
    password db 'medica$'
    incorrect_password db 10, 13, 'Invalid password! Try again.$'
    welcome db 10, 13, 'WELCOME TO MEDICAL STORE$'
    msg1 db 10, 13, 'Choose an option:$'
    msg_medicines db 10, 13, '1. Buy Medicine$'
    medicines_sold db 10, 13, '2. View Medicines Sold$'
    amount_print db 10, 13, '3. Show Total Bill$'
    total_medicines_msg db 10, 13, '4. Total Medicines Sold$'
    reset_sales_msg db 10, 13, '5. Reset Sales Data$'
    view_prices_msg db 10, 13, '6. View Medicine Prices$'
    exit_program db 10, 13, '7. Exit    choice:$'
    wrong_input db 10, 13, 'Wrong input! Try again.$'
    input_again db 10, 13, 'Press a valid key: $'
    total_msg db 10, 13, 'Total earned: $'
    amount_earned db 10, 13, 'Amount earned: $'
    newline db 10, 13, '$'

   
    opt1 db 10, 13, '1. Panadol - 10rs$'
    opt2 db 10, 13, '2. Paracetamol - 10rs$'
    opt3 db 10, 13, '3. Cleritek - 30rs$'
    opt4 db 10, 13, '4. Aspirin - 40rs$'
    opt5 db 10, 13, '5. Brufen - 50rs$'
    opt6 db 10, 13, '6. Surbex - 50rs$'
    opt7 db 10, 13, '7. Arimac - 60rs$'
    opt8 db 10, 13, '8. Sinopharm Vaccine - 80rs$'
    opt9 db 10, 13, '9. Pfizer Vaccine - 90rs$'

    
    msg_panadol db 10, 13, 'How many Panadols do you want to buy? $'
    msg_paracetamol db 10, 13, 'How many Paracetamols do you want to buy? $'
    msg_cleritek db 10, 13, 'How many Cleriteks do you want to buy? $'
    msg_aspirin db 10, 13, 'How many Aspirins do you want to buy? $'
    msg_brufen db 10, 13, 'How many Brufens do you want to buy? $'
    msg_surbex db 10, 13, 'How many Surbexes do you want to buy? $'
    msg_arimac db 10, 13, 'How many Arimacs do you want to buy? $'
    msg_sinopharm db 10, 13, 'How many Sinopharm Vaccines do you want to buy? $'
    msg_pfizer db 10, 13, 'How many Pfizer Vaccines do you want to buy? $'

    
    price_panadol dw 10
    price_paracetamol dw 10
    price_cleritek dw 30
    price_aspirin dw 40
    price_brufen dw 50
    price_surbex dw 50
    price_arimac dw 60
    price_sinopharm dw 80
    price_pfizer dw 90

    
    panadol_sold db 0
    paracetamol_sold db 0
    cleritek_sold db 0
    aspirin_sold db 0
    brufen_sold db 0
    surbex_sold db 0
    arimac_sold db 0
    sinopharm_sold db 0
    pfizer_sold db 0
    amount dw 0

    
    panadol_print db 10, 13, 'Panadols sold: $'
    paracetamol_print db 10, 13, 'Paracetamols sold: $'
    cleritek_print db 10, 13, 'Cleriteks sold: $'
    aspirin_print db 10, 13, 'Aspirins sold: $'
    brufen_print db 10, 13, 'Brufens sold: $'
    surbex_print db 10, 13, 'Surbexes sold: $'
    arimac_print db 10, 13, 'Arimacs sold: $'
    sinopharm_print db 10, 13, 'Sinopharm Vaccines sold: $'
    pfizer_print db 10, 13, 'Pfizer Vaccines sold: $'

.code
main proc
    mov ax, @data
    mov ds, ax

    
password_input:
    mov dx, offset input_password
    mov ah, 9
    int 21h

    mov bx, offset password
    mov cx, 6

password_loop:
    mov ah, 1
    int 21h
    cmp al, [bx]
    jne incorrect
    inc bx
    loop password_loop

    jmp start

incorrect:
    mov dx, offset incorrect_password
    mov ah, 9
    int 21h
    jmp password_input

start:
    call menu

    
    mov ah, 1
    int 21h

    
    cmp al, '1'
    je menu2
    cmp al, '2'
    je medicines_stats
    cmp al, '3'
    je show_amount
    cmp al, '4'
    je total_medicines
    cmp al, '5'
    je reset_sales
    cmp al, '6'
    je view_prices
    cmp al, '7'
    je exit
    

    
    mov dx, offset wrong_input
    mov ah, 9
    int 21h
    jmp start

menu2:
    call display_medicine_menu

    
    mov ah, 1
    int 21h

    
    cmp al, '1'
    je panadol
    cmp al, '2'
    je paracetamol
    cmp al, '3'
    je cleritek
    cmp al, '4'
    je aspirin
    cmp al, '5'
    je brufen
    cmp al, '6'
    je surbex
    cmp al, '7'
    je arimac
    cmp al, '8'
    je sinopharm
    cmp al, '9'
    je pfizer

    
    mov dx, offset wrong_input
    mov ah, 9
    int 21h
    jmp menu2

panadol:
    call buy_medicine
    mov dx, offset msg_panadol
    mov ah, 9
    int 21h
    call get_quantity
    add panadol_sold, al
    mov ax, price_panadol
    mul bx
    add amount, ax
    jmp start

paracetamol:
    call buy_medicine
    mov dx, offset msg_paracetamol
    mov ah, 9
    int 21h
    call get_quantity
    add paracetamol_sold, al
    mov ax, price_paracetamol
    mul bx
    add amount, ax
    jmp start

cleritek:
    call buy_medicine
    mov dx, offset msg_cleritek
    mov ah, 9
    int 21h
    call get_quantity
    add cleritek_sold, al
    mov ax, price_cleritek
    mul bx
    add amount, ax
    jmp start

aspirin:
    call buy_medicine
    mov dx, offset msg_aspirin
    mov ah, 9
    int 21h
    call get_quantity
    add aspirin_sold, al
    mov ax, price_aspirin
    mul bx
    add amount, ax
    jmp start

brufen:
    call buy_medicine
    mov dx, offset msg_brufen
    mov ah, 9
    int 21h
    call get_quantity
    add brufen_sold, al
    mov ax, price_brufen
    mul bx
    add amount, ax
    jmp start

surbex:
    call buy_medicine
    mov dx, offset msg_surbex
    mov ah, 9
    int 21h
    call get_quantity
    add surbex_sold, al
    mov ax, price_surbex
    mul bx
    add amount, ax
    jmp start

arimac:
    call buy_medicine
    mov dx, offset msg_arimac
    mov ah, 9
    int 21h
    call get_quantity
    add arimac_sold, al
    mov ax, price_arimac
    mul bx
    add amount, ax
    jmp start

sinopharm:
    call buy_medicine
    mov dx, offset msg_sinopharm
    mov ah, 9
    int 21h
    call get_quantity
    add sinopharm_sold, al
    mov ax, price_sinopharm
    mul bx
    add amount, ax
    jmp start

pfizer:
    call buy_medicine
    mov dx, offset msg_pfizer
    mov ah, 9
    int 21h
    call get_quantity
    add pfizer_sold, al
    mov ax, price_pfizer
    mul bx
    add amount, ax
    jmp start

show_amount:
    mov dx, offset amount_earned
    mov ah, 9
    int 21h
    mov ax, amount
    call display_number
    jmp start

medicines_stats:
    call display_sales_stats
    jmp start

reset_sales:
    
    mov panadol_sold, 0
    mov paracetamol_sold, 0
    mov cleritek_sold, 0
    mov aspirin_sold, 0
    mov brufen_sold, 0
    mov surbex_sold, 0
    mov arimac_sold, 0
    mov sinopharm_sold, 0
    mov pfizer_sold, 0
    mov amount, 0
    mov dx, offset newline
    mov ah, 9
    int 21h
    mov dx, offset reset_sales_msg
    mov ah, 9
    int 21h
    jmp start

view_prices:
    call display_medicine_menu
    jmp start

total_medicines:
    
    mov al, panadol_sold
    add al, paracetamol_sold
    add al, cleritek_sold
    add al, aspirin_sold
    add al, brufen_sold
    add al, surbex_sold
    add al, arimac_sold
    add al, sinopharm_sold
    add al, pfizer_sold
    mov ah, 0
    call display_number
    jmp start

exit:
    mov ah, 4Ch
    int 21h

main endp


menu proc
    mov dx, offset welcome
    mov ah, 9
    int 21h
    mov dx, offset msg1
    mov ah, 9
    int 21h
    mov dx, offset msg_medicines
    mov ah, 9
    int 21h
    mov dx, offset medicines_sold
    mov ah, 9
    int 21h
    mov dx, offset amount_print
    mov ah, 9
    int 21h
    mov dx, offset total_medicines_msg
    mov ah, 9
    int 21h
    mov dx, offset reset_sales_msg
    mov ah, 9
    int 21h
    mov dx, offset view_prices_msg
    mov ah, 9
    int 21h
    mov dx, offset exit_program
    mov ah, 9
    int 21h
    
    ret
menu endp

display_medicine_menu proc
    mov dx, offset opt1
    mov ah, 9
    int 21h
    mov dx, offset opt2
    mov ah, 9
    int 21h
    mov dx, offset opt3
    mov ah, 9
    int 21h
    mov dx, offset opt4
    mov ah, 9
    int 21h
    mov dx, offset opt5
    mov ah, 9
    int 21h
    mov dx, offset opt6
    mov ah, 9
    int 21h
    mov dx, offset opt7
    mov ah, 9
    int 21h
    mov dx, offset opt8
    mov ah, 9
    int 21h
    mov dx, offset opt9
    mov ah, 9
    int 21h
    ret
display_medicine_menu endp

buy_medicine proc
    ret
buy_medicine endp

get_quantity proc
    mov ah, 1
    int 21h
    sub al, 48
    mov bl, al
    ret
get_quantity endp

display_sales_stats proc
    mov dx, offset panadol_print
    mov ah, 9
    int 21h
    mov dl, panadol_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset paracetamol_print
    mov ah, 9
    int 21h
    mov dl, paracetamol_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset cleritek_print
    mov ah, 9
    int 21h
    mov dl, cleritek_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset aspirin_print
    mov ah, 9
    int 21h
    mov dl, aspirin_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset brufen_print
    mov ah, 9
    int 21h
    mov dl, brufen_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset surbex_print
    mov ah, 9
    int 21h
    mov dl, surbex_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset arimac_print
    mov ah, 9
    int 21h
    mov dl, arimac_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset sinopharm_print
    mov ah, 9
    int 21h
    mov dl, sinopharm_sold
    add dl, 48
    mov ah, 2
    int 21h

    mov dx, offset pfizer_print
    mov ah, 9
    int 21h
    mov dl, pfizer_sold
    add dl, 48
    mov ah, 2
    int 21h

    ret
display_sales_stats endp

display_number proc
    mov cx, 10
    xor dx, dx
    div cx
    push dx
    cmp ax, 0
    je display_digit
    call display_number
display_digit:
    pop dx
    add dl, 48
    mov ah, 2
    int 21h
    ret
display_number endp

end main