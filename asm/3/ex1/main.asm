; ------------------------------------------------------------------------------
; Fonction qui passe en majuscule tous les caract�res d'une cha�ne de caract�res
; Technique :
; a = $41 = 0100 0001
; A = $61 = 0110 0001
; faire un OU avec
;         b 0010 0000 = d 32
; ------------------------------------------------------------------------------

extern printf	; fonction C externe, utilis�e par ce programme

;; Segment des donn�es
section .data
	msg_a		db "abcdefg",10,0	; chaine � passer � la fonction printf (doit se terminer par zero)
	msg_a_len	equ $ - msg_a - 2	;7 taill de la chaine
	msg_result	db "%c",0
	result		db "",10,0


;; Segment de code
section .texte

	
global main			; export du point d'entr�e du programme
main:				; point d'entr�e standard du C (ligne "int main(void)")
	; la fonction C print r�cup�re ses param�tres � partir
	; de la position m�moire point�e par ebp, dans la pile
	
	push	ebp		; sauvegarde de ebp
	mov	ebp, esp	; ebp pointe maintenant sur le haut de la pile

	mov	esi, msg_a
	mov	edi, result
	mov	ecx, msg_a_len
	mov	eax, 0

boucle:
	lodsb
	cmp	ecx,0
	je	boucle_affich
	sub	eax, 32
	stosb
	loop	boucle

boucle_affich:
	push	dword result
	call	printf
	;add	esp,4
	;cmp	ecx,0
	;jne	boucle_affich

	mov	esp, ebp

	pop	ebp		; restauration de ebp
	mov	eax, 0		; code de retour de la fonction main (ligne "return 0")
	ret			; sort de la fonction "main"
