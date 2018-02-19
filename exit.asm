section .text ; 섹션 시작
global _start ; 
_start:;      ; 링커로 하여금 오류나 추측 방지
xor eax, eax  ; eax 레지스터 0으로 채우기(safe)
xor ebx, ebx  ; ebx 레지스터 0으로 채우기(노트 참고)
mov al, 0x01  ; 한 바이트에만 영향을 줌. 다른 24비트의 패딩은 중지
int 0x80      ; syscall을 실행하고자 커널호출