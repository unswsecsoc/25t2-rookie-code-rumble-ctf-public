.data
menu: .asciiz "2hollis is coming back to Sydney!\nBut his tickets are selling fast, and there's only 1 ticket left. Due to the outrageous demand for it, it's going on auction!\nTry to outbid everyone to win the ticket.\n\n"
prompt_bid: .asciiz "Enter your bid: "
low_bid: .asciiz "Your bid must be higher than the current highest bid ($"
rival_outbid: .asciiz "You have been outbid! The highest bid is now $"
newline: .asciiz "\n"
closing_paren: .asciiz ").\n"
invalid_bid: .asciiz "Bids must be non-negative.\n"
win_msg: .asciiz "\nYou win the auction! See you at the concert <2\nRCR{h0ll1s_s1GN_MY_inT3g3r_plzd10c42}\n"

.text
.globl main

main:
    li $s0, 0          # your_bid = 0
    li $s1, 1          # rival_bid = 1, you were never going to win this

    li $v0, 4
    la $a0, menu
    syscall

main_loop:
    li $v0, 4
    la $a0, prompt_bid
    syscall

    li $v0, 5
    syscall
    move $t0, $v0    

    bltz $t0, bid_negative

    move $s0, $t0

    bleu $s0, $s1, too_low

    addu $s1, $s0, 1

    bltz $s1, you_win # wait... how do you even bid negative?

    li $v0, 4
    la $a0, rival_outbid
    syscall

    li $v0, 1
    move $a0, $s1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    j main_loop

too_low:
    li $v0, 4
    la $a0, low_bid
    syscall

    li $v0, 1
    move $a0, $s1
    syscall

    li $v0, 4
    la $a0, closing_paren
    syscall

    j main_loop

bid_negative:
    li $v0, 4
    la $a0, invalid_bid
    syscall

    j main_loop

you_win:
    li $v0, 4
    la $a0, win_msg
    syscall

    li $v0, 10
    syscall
