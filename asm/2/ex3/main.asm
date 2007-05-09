; -------------------------------------------
; Programme affichant le maximum de 3 nombres
; -------------------------------------------

extern printf	; fonction C externe, utilis�e par ce programme

;; Segment des donn�es
section .data
	msg_x:	db "x=%i",10,0	; chaine � passer � la fonction printf (doit se terminer par zero)
	x:	dd 15		; chaine 32 bits (double mot)
	msg_y:	db "y=%i",10,0 	; 10=retour chariot 0=caract�re de fin de chaine
	y:	dd 61
	msg_z:  db "z=%i",10,0
	z:	dd 10
	msg_res: db "max(x,y,z)=%i",10,0


;; Segment de code
section .text

	
global main			; export du point d'entr�e du programme
main:				; point d'entr�e standard du C (ligne "int main(void)")
	; la fonction C print r�cup�re ses param�tres � partir
	; de la position m�moire point�e par ebp, dans la pile
	
	push	ebp		; sauvegarde de ebp
	mov	ebp, esp	; ebp pointe maintenant sur le haut de la pile

	push	dword [x]	; le contenu de la variable "x" est empil�
	push 	dword msg_x	; l'adresse de la chaine de caractere � afficher est empil�e
	call 	printf		; appel de la fonction C printf

	push	dword [y]
	push	dword msg_y
	call	printf		; appel de la fonction C printf

	push	dword [z]
	push	dword msg_z
	call	printf

	mov     eax,dword[x]
	mov	ebx,dword[y]
	cmp	eax,ebx
	JA	x_sup_y
	JB	y_sup_x

x_sup_y:
	mov	eax,dword[x]
	jmp	fin_cmp_x_y

y_sup_x:
	mov	eax,dword[y]
	jmp	fin_cmp_x_y

fin_cmp_x_y:
	mov	ebx,dword[z]
	cmp	eax,ebx
	JA	xy_sup_z
	JB	xy_sup_z

xy_sup_z:
	; xy deja dans eax
	jmp 	fin

z_sup_xy:
	mov	eax,dword[z]


fin:
	push	eax
	push	dword msg_res
	call	printf



	mov	esp, ebp	; remet esp dans ebp

	pop	ebp		; restauration de ebp
	mov	eax, 0		; code de retour de la fonction main (ligne "return 0")
	ret			; sort de la fonction "main"
