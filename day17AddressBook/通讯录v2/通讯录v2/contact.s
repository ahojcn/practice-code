	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_LogInfo                ## -- Begin function LogInfo
	.p2align	4, 0x90
_LogInfo:                               ## @LogInfo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rsi
	cmpq	$0, %rsi
	je	LBB0_2
## %bb.1:
	leaq	L___func__.LogInfo(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.1(%rip), %rcx
	movl	$6, %edx
	callq	___assert_rtn
LBB0_2:
	jmp	LBB0_3
LBB0_3:
	cmpq	$0, -16(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdx
	cmpq	$0, %rdx
	je	LBB0_5
## %bb.4:
	leaq	L___func__.LogInfo(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.2(%rip), %rcx
	movl	$7, %edx
	callq	___assert_rtn
LBB0_5:
	jmp	LBB0_6
LBB0_6:
	leaq	L_.str.3(%rip), %rdi
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdx
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ContactIsFull          ## -- Begin function ContactIsFull
	.p2align	4, 0x90
_ContactIsFull:                         ## @ContactIsFull
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB1_2
## %bb.1:
	leaq	L___func__.ContactIsFull(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$13, %edx
	callq	___assert_rtn
LBB1_2:
	jmp	LBB1_3
LBB1_3:
	xorl	%eax, %eax
	movl	$1, %ecx
	movq	-8(%rbp), %rdx
	movl	4(%rdx), %esi
	movq	-8(%rbp), %rdx
	movl	(%rdx), %edi
	cmpl	%edi, %esi
	cmovel	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ContactIsEmpty         ## -- Begin function ContactIsEmpty
	.p2align	4, 0x90
_ContactIsEmpty:                        ## @ContactIsEmpty
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB2_2
## %bb.1:
	leaq	L___func__.ContactIsEmpty(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$19, %edx
	callq	___assert_rtn
LBB2_2:
	jmp	LBB2_3
LBB2_3:
	xorl	%eax, %eax
	movl	$1, %ecx
	movq	-8(%rbp), %rdx
	movl	4(%rdx), %esi
	cmpl	$0, %esi
	cmovel	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_MenuUnlogin            ## -- Begin function MenuUnlogin
	.p2align	4, 0x90
_MenuUnlogin:                           ## @MenuUnlogin
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.6(%rip), %rsi
	callq	_LogInfo
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.8(%rip), %rdi
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.9(%rip), %rdi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.10(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.11(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_MainMenu               ## -- Begin function MainMenu
	.p2align	4, 0x90
_MainMenu:                              ## @MainMenu
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -56(%rbp)
	cmpq	$0, -56(%rbp)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movslq	%edx, %rax
	cmpq	$0, %rax
	je	LBB4_2
## %bb.1:
	leaq	L___func__.MainMenu(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.12(%rip), %rcx
	movl	$36, %edx
	callq	___assert_rtn
LBB4_2:
	jmp	LBB4_3
LBB4_3:
	movl	$30, %eax
	movl	%eax, %edx
	leaq	-48(%rbp), %rdi
	movq	l_MainMenu.msg(%rip), %rcx
	movq	%rcx, -48(%rbp)
	movq	l_MainMenu.msg+8(%rip), %rcx
	movq	%rcx, -40(%rbp)
	movq	l_MainMenu.msg+16(%rip), %rcx
	movq	%rcx, -32(%rbp)
	movl	l_MainMenu.msg+24(%rip), %eax
	movl	%eax, -24(%rbp)
	movw	l_MainMenu.msg+28(%rip), %si
	movw	%si, -20(%rbp)
	movq	-56(%rbp), %rsi
	callq	___strcat_chk
	leaq	L_.str.5(%rip), %rdi
	leaq	-48(%rbp), %rsi
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	callq	_LogInfo
	leaq	L_.str.13(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.14(%rip), %rdi
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.15(%rip), %rdi
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.16(%rip), %rdi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.17(%rip), %rdi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.18(%rip), %rdi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.19(%rip), %rdi
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.20(%rip), %rdi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.13(%rip), %rdi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.11(%rip), %rdi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	jne	LBB4_5
## %bb.4:                               ## %SP_return
	addq	$112, %rsp
	popq	%rbp
	retq
LBB4_5:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_GetFileName            ## -- Begin function GetFileName
	.p2align	4, 0x90
_GetFileName:                           ## @GetFileName
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB5_2
## %bb.1:
	leaq	L___func__.GetFileName(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.12(%rip), %rcx
	movl	$53, %edx
	callq	___assert_rtn
LBB5_2:
	jmp	LBB5_3
LBB5_3:
	movl	$30, %eax
	movl	%eax, %edi
	callq	_malloc
	movq	$-1, %rdx
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	-8(%rbp), %rsi
	callq	___strcpy_chk
	leaq	L_.str.21(%rip), %rsi
	movq	$-1, %rdx
	movq	-16(%rbp), %rdi
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	___strcat_chk
	movq	-16(%rbp), %rdx
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movq	%rdx, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_UserLogin              ## -- Begin function UserLogin
	.p2align	4, 0x90
_UserLogin:                             ## @UserLogin
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$224, %rsp
	leaq	L_.str.22(%rip), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	$0, -152(%rbp)
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-48(%rbp), %rsi
	movl	%eax, -156(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.24(%rip), %rsi
	leaq	-48(%rbp), %rdi
	movl	%eax, -160(%rbp)        ## 4-byte Spill
	callq	_fopen
	movq	%rax, -152(%rbp)
	cmpq	$0, -152(%rbp)
	jne	LBB6_2
## %bb.1:
	movl	$30, %eax
	movl	%eax, %edx
	leaq	-48(%rbp), %rsi
	leaq	-80(%rbp), %rdi
	movq	l_UserLogin.msg(%rip), %rcx
	movq	%rcx, -80(%rbp)
	movq	l_UserLogin.msg+8(%rip), %rcx
	movq	%rcx, -72(%rbp)
	movq	l_UserLogin.msg+16(%rip), %rcx
	movq	%rcx, -64(%rbp)
	movl	l_UserLogin.msg+24(%rip), %eax
	movl	%eax, -56(%rbp)
	movw	l_UserLogin.msg+28(%rip), %r8w
	movw	%r8w, -52(%rbp)
	callq	___strcat_chk
	leaq	L_.str.25(%rip), %rsi
	movl	$30, %r9d
	movl	%r9d, %edx
	leaq	-80(%rbp), %rdi
	movq	%rax, -168(%rbp)        ## 8-byte Spill
	callq	___strcat_chk
	leaq	L_.str.26(%rip), %rdi
	leaq	-80(%rbp), %rsi
	movq	%rax, -176(%rbp)        ## 8-byte Spill
	callq	_LogInfo
	movq	-152(%rbp), %rdi
	callq	_fclose
	movl	%eax, -180(%rbp)        ## 4-byte Spill
	jmp	LBB6_6
LBB6_2:
	leaq	L_.str.23(%rip), %rsi
	leaq	-48(%rbp), %rax
	movq	-152(%rbp), %rdi
	addq	$20, %rax
	movq	%rax, %rdx
	movb	$0, %al
	callq	_fscanf
	leaq	L_.str.27(%rip), %rdi
	movl	%eax, -184(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-112(%rbp), %rsi
	movl	%eax, -188(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	xorl	%ecx, %ecx
	leaq	-48(%rbp), %rdx
	leaq	-112(%rbp), %rdi
	addq	$20, %rdx
	movq	%rdx, %rsi
	movl	%eax, -192(%rbp)        ## 4-byte Spill
	movl	%ecx, -196(%rbp)        ## 4-byte Spill
	callq	_strcmp
	movl	-196(%rbp), %ecx        ## 4-byte Reload
	cmpl	%eax, %ecx
	jne	LBB6_4
## %bb.3:
	movaps	l_UserLogin.msg.28(%rip), %xmm0
	movaps	%xmm0, -144(%rbp)
	movq	$0, -122(%rbp)
	movq	$0, -128(%rbp)
	movl	$30, %eax
	movl	%eax, %edx
	leaq	-144(%rbp), %rcx
	leaq	-48(%rbp), %rsi
	movq	%rcx, %rdi
	movq	%rsi, -208(%rbp)        ## 8-byte Spill
	movq	%rcx, -216(%rbp)        ## 8-byte Spill
	callq	___strcat_chk
	leaq	L_.str.5(%rip), %rdi
	movq	-216(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, -224(%rbp)        ## 8-byte Spill
	callq	_LogInfo
	movq	-208(%rbp), %rdi        ## 8-byte Reload
	callq	_MainCtrl
	xorl	%edi, %edi
	callq	_exit
LBB6_4:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.29(%rip), %rsi
	callq	_LogInfo
## %bb.5:
	jmp	LBB6_6
LBB6_6:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB6_8
## %bb.7:                               ## %SP_return
	xorl	%eax, %eax
	addq	$224, %rsp
	popq	%rbp
	retq
LBB6_8:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_MainCtrl               ## -- Begin function MainCtrl
	.p2align	4, 0x90
_MainCtrl:                              ## @MainCtrl
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB7_2
## %bb.1:
	leaq	L___func__.MainCtrl(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.12(%rip), %rcx
	movl	$422, %edx              ## imm = 0x1A6
	callq	___assert_rtn
LBB7_2:
	jmp	LBB7_3
LBB7_3:
	movl	$1, -12(%rbp)
	movq	$0, -24(%rbp)
	movq	-8(%rbp), %rdi
	callq	_ContactInit
	movq	%rax, -24(%rbp)
LBB7_4:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -12(%rbp)
	je	LBB7_15
## %bb.5:                               ##   in Loop: Header=BB7_4 Depth=1
	movq	-8(%rbp), %rdi
	callq	_MainMenu
	leaq	L_.str.34(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	leaq	-12(%rbp), %rsi
	movb	%cl, %al
	callq	_scanf
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movq	%rsi, %rdi
	subq	$6, %rdi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movq	%rsi, -40(%rbp)         ## 8-byte Spill
	movq	%rdi, -48(%rbp)         ## 8-byte Spill
	ja	LBB7_13
## %bb.16:                              ##   in Loop: Header=BB7_4 Depth=1
	leaq	LJTI7_0(%rip), %rax
	movq	-40(%rbp), %rcx         ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB7_6:
	movq	-24(%rbp), %rdi
	movq	-8(%rbp), %rsi
	callq	_SaveToFile
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.35(%rip), %rsi
	callq	_LogInfo
	jmp	LBB7_15
LBB7_7:                                 ##   in Loop: Header=BB7_4 Depth=1
	movq	-24(%rbp), %rdi
	callq	_AddPeople
	jmp	LBB7_14
LBB7_8:                                 ##   in Loop: Header=BB7_4 Depth=1
	movq	-24(%rbp), %rdi
	callq	_SearchPeople
	jmp	LBB7_14
LBB7_9:                                 ##   in Loop: Header=BB7_4 Depth=1
	movq	-24(%rbp), %rdi
	callq	_SortPeople
	jmp	LBB7_14
LBB7_10:                                ##   in Loop: Header=BB7_4 Depth=1
	movq	-24(%rbp), %rdi
	callq	_DeletePeople
	jmp	LBB7_14
LBB7_11:                                ##   in Loop: Header=BB7_4 Depth=1
	movq	-24(%rbp), %rdi
	callq	_DispAllPeople
	jmp	LBB7_14
LBB7_12:                                ##   in Loop: Header=BB7_4 Depth=1
	movq	-24(%rbp), %rdi
	movq	-8(%rbp), %rsi
	callq	_ClearAllPeople
	jmp	LBB7_14
LBB7_13:                                ##   in Loop: Header=BB7_4 Depth=1
	leaq	L_.str.68(%rip), %rdi
	leaq	L_.str.36(%rip), %rsi
	callq	_LogInfo
LBB7_14:                                ##   in Loop: Header=BB7_4 Depth=1
	jmp	LBB7_4
LBB7_15:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
L7_0_set_6 = LBB7_6-LJTI7_0
L7_0_set_7 = LBB7_7-LJTI7_0
L7_0_set_8 = LBB7_8-LJTI7_0
L7_0_set_9 = LBB7_9-LJTI7_0
L7_0_set_10 = LBB7_10-LJTI7_0
L7_0_set_11 = LBB7_11-LJTI7_0
L7_0_set_12 = LBB7_12-LJTI7_0
LJTI7_0:
	.long	L7_0_set_6
	.long	L7_0_set_7
	.long	L7_0_set_8
	.long	L7_0_set_9
	.long	L7_0_set_10
	.long	L7_0_set_11
	.long	L7_0_set_12
	.end_data_region
                                        ## -- End function
	.globl	_UserRegist             ## -- Begin function UserRegist
	.p2align	4, 0x90
_UserRegist:                            ## @UserRegist
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	$0, -96(%rbp)
	movl	$1, -100(%rbp)
LBB8_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -100(%rbp)
	je	LBB8_5
## %bb.2:                               ##   in Loop: Header=BB8_1 Depth=1
	leaq	L_.str.22(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-48(%rbp), %rsi
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.24(%rip), %rsi
	leaq	-48(%rbp), %rdi
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	callq	_fopen
	movq	%rax, -96(%rbp)
	cmpq	$0, -96(%rbp)
	je	LBB8_4
## %bb.3:                               ##   in Loop: Header=BB8_1 Depth=1
	movq	-96(%rbp), %rdi
	callq	_fclose
	movl	$30, %ecx
	movl	%ecx, %edx
	leaq	-48(%rbp), %rsi
	leaq	-80(%rbp), %rdi
	movq	l_UserRegist.msg(%rip), %r8
	movq	%r8, -80(%rbp)
	movq	l_UserRegist.msg+8(%rip), %r8
	movq	%r8, -72(%rbp)
	movq	l_UserRegist.msg+16(%rip), %r8
	movq	%r8, -64(%rbp)
	movl	l_UserRegist.msg+24(%rip), %ecx
	movl	%ecx, -56(%rbp)
	movw	l_UserRegist.msg+28(%rip), %r9w
	movw	%r9w, -52(%rbp)
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	callq	___strcat_chk
	leaq	L_.str.30(%rip), %rsi
	movl	$30, %ecx
	movl	%ecx, %edx
	leaq	-80(%rbp), %rdi
	movq	%rax, -120(%rbp)        ## 8-byte Spill
	callq	___strcat_chk
	leaq	L_.str.26(%rip), %rdi
	leaq	-80(%rbp), %rsi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	_LogInfo
	movl	$1, -100(%rbp)
	jmp	LBB8_1
LBB8_4:                                 ##   in Loop: Header=BB8_1 Depth=1
	movl	$0, -100(%rbp)
	jmp	LBB8_1
LBB8_5:
	leaq	L_.str.27(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-48(%rbp), %rcx
	addq	$20, %rcx
	movq	%rcx, %rsi
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.31(%rip), %rsi
	leaq	-48(%rbp), %rdi
	movl	%eax, -136(%rbp)        ## 4-byte Spill
	callq	_fopen
	movq	%rax, -96(%rbp)
	cmpq	$0, -96(%rbp)
	jne	LBB8_7
## %bb.6:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.32(%rip), %rsi
	callq	_LogInfo
	movl	$0, -84(%rbp)
	jmp	LBB8_9
LBB8_7:
	leaq	L_.str.23(%rip), %rsi
	leaq	-48(%rbp), %rax
	movq	-96(%rbp), %rdi
	addq	$20, %rax
	movq	%rax, %rdx
	movb	$0, %al
	callq	_fprintf
	movq	-96(%rbp), %rdi
	movl	%eax, -140(%rbp)        ## 4-byte Spill
	callq	_fclose
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.33(%rip), %rsi
	movl	%eax, -144(%rbp)        ## 4-byte Spill
	callq	_LogInfo
## %bb.8:
	movl	$0, -84(%rbp)
LBB8_9:
	movl	-84(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -148(%rbp)        ## 4-byte Spill
	jne	LBB8_11
## %bb.10:                              ## %SP_return
	movl	-148(%rbp), %eax        ## 4-byte Reload
	addq	$160, %rsp
	popq	%rbp
	retq
LBB8_11:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_LoginCtrl              ## -- Begin function LoginCtrl
	.p2align	4, 0x90
_LoginCtrl:                             ## @LoginCtrl
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$1, -4(%rbp)
LBB9_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -4(%rbp)
	je	LBB9_8
## %bb.2:                               ##   in Loop: Header=BB9_1 Depth=1
	callq	_MenuUnlogin
	leaq	L_.str.34(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	leaq	-4(%rbp), %rsi
	movb	%cl, %al
	callq	_scanf
	movl	-4(%rbp), %edx
	testl	%edx, %edx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%edx, -12(%rbp)         ## 4-byte Spill
	je	LBB9_3
	jmp	LBB9_9
LBB9_9:                                 ##   in Loop: Header=BB9_1 Depth=1
	movl	-12(%rbp), %eax         ## 4-byte Reload
	subl	$1, %eax
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	je	LBB9_4
	jmp	LBB9_10
LBB9_10:                                ##   in Loop: Header=BB9_1 Depth=1
	movl	-12(%rbp), %eax         ## 4-byte Reload
	subl	$2, %eax
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	je	LBB9_5
	jmp	LBB9_6
LBB9_3:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.35(%rip), %rsi
	callq	_LogInfo
	xorl	%edi, %edi
	callq	_exit
LBB9_4:                                 ##   in Loop: Header=BB9_1 Depth=1
	callq	_UserLogin
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	jmp	LBB9_7
LBB9_5:                                 ##   in Loop: Header=BB9_1 Depth=1
	callq	_UserRegist
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB9_7
LBB9_6:                                 ##   in Loop: Header=BB9_1 Depth=1
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.36(%rip), %rsi
	callq	_LogInfo
LBB9_7:                                 ##   in Loop: Header=BB9_1 Depth=1
	jmp	LBB9_1
LBB9_8:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ContactInit            ## -- Begin function ContactInit
	.p2align	4, 0x90
_ContactInit:                           ## @ContactInit
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -64(%rbp)
	cmpq	$0, -64(%rbp)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movslq	%edx, %rax
	cmpq	$0, %rax
	je	LBB10_2
## %bb.1:
	leaq	L___func__.ContactInit(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.12(%rip), %rcx
	movl	$168, %edx
	callq	___assert_rtn
LBB10_2:
	jmp	LBB10_3
LBB10_3:
	movl	$14308, %eax            ## imm = 0x37E4
	movl	%eax, %edi
	callq	_malloc
	movq	%rax, -72(%rbp)
	cmpq	$0, -72(%rbp)
	jne	LBB10_5
## %bb.4:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.37(%rip), %rsi
	callq	_LogInfo
	movq	$0, -56(%rbp)
	jmp	LBB10_14
LBB10_5:
	leaq	-48(%rbp), %rdi
	movq	-64(%rbp), %rax
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	_GetFileName
	movl	$30, %ecx
	movl	%ecx, %edx
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rsi
	callq	___strcpy_chk
	leaq	L_.str.24(%rip), %rsi
	leaq	-48(%rbp), %rdi
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	callq	_fopen
	movq	%rax, -80(%rbp)
	cmpq	$0, -80(%rbp)
	jne	LBB10_10
## %bb.6:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.38(%rip), %rsi
	callq	_LogInfo
	leaq	L_.str.39(%rip), %rsi
	leaq	-48(%rbp), %rdi
	callq	_fopen
	movq	%rax, -80(%rbp)
	cmpq	$0, -80(%rbp)
	jne	LBB10_8
## %bb.7:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.40(%rip), %rsi
	callq	_LogInfo
	movq	$0, -56(%rbp)
	jmp	LBB10_14
LBB10_8:
	movq	-80(%rbp), %rdi
	callq	_fclose
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.41(%rip), %rsi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	callq	_LogInfo
	movq	-72(%rbp), %rsi
	movl	$100, (%rsi)
	movq	-72(%rbp), %rsi
	movl	$0, 4(%rsi)
## %bb.9:
	jmp	LBB10_13
LBB10_10:
	leaq	L_.str.39(%rip), %rsi
	leaq	-48(%rbp), %rdi
	callq	_fopen
	movl	$8, %ecx
	movl	%ecx, %esi
	movl	$1, %ecx
	movl	%ecx, %edx
	movq	%rax, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rcx
	movq	%rax, %rdi
	callq	_fread
	movq	-72(%rbp), %rcx
	movslq	(%rcx), %rcx
	imulq	$143, %rcx, %rcx
	addq	$8, %rcx
	movq	%rcx, %rdi
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	callq	_malloc
	movq	%rax, -72(%rbp)
	cmpq	$0, -72(%rbp)
	jne	LBB10_12
## %bb.11:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.42(%rip), %rsi
	callq	_LogInfo
	movq	$0, -56(%rbp)
	jmp	LBB10_14
LBB10_12:
	movl	$1, %eax
	movl	%eax, %edx
	movq	-72(%rbp), %rcx
	addq	$8, %rcx
	movq	-72(%rbp), %rsi
	movslq	4(%rsi), %rsi
	imulq	$143, %rsi, %rsi
	movq	-80(%rbp), %rdi
	movq	%rdi, -120(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdi
	movq	-120(%rbp), %rcx        ## 8-byte Reload
	callq	_fread
	movq	-80(%rbp), %rdi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	_fclose
	movq	-72(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	jmp	LBB10_14
LBB10_13:
	movq	-72(%rbp), %rax
	movq	%rax, -56(%rbp)
LBB10_14:
	movq	-56(%rbp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movq	%rax, -144(%rbp)        ## 8-byte Spill
	jne	LBB10_16
## %bb.15:                              ## %SP_return
	movq	-144(%rbp), %rax        ## 8-byte Reload
	addq	$144, %rsp
	popq	%rbp
	retq
LBB10_16:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_IncContact             ## -- Begin function IncContact
	.p2align	4, 0x90
_IncContact:                            ## @IncContact
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB11_2
## %bb.1:
	leaq	L___func__.IncContact(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.43(%rip), %rcx
	movl	$220, %edx
	callq	___assert_rtn
LBB11_2:
	jmp	LBB11_3
LBB11_3:
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %ecx
	shll	$1, %ecx
	movl	%ecx, -20(%rbp)
	movslq	-20(%rbp), %rax
	imulq	$143, %rax, %rax
	shlq	$1, %rax
	addq	$8, %rax
	movl	%eax, %ecx
	movl	%ecx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movslq	-24(%rbp), %rsi
	movq	%rax, %rdi
	callq	_realloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB11_5
## %bb.4:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.44(%rip), %rsi
	callq	_LogInfo
	movl	$0, -4(%rbp)
	jmp	LBB11_6
LBB11_5:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.45(%rip), %rsi
	movl	-20(%rbp), %eax
	movq	-32(%rbp), %rcx
	movl	%eax, (%rcx)
	movq	-32(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	%rcx, (%rdx)
	callq	_LogInfo
	movl	$1, -4(%rbp)
LBB11_6:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_AddPeople              ## -- Begin function AddPeople
	.p2align	4, 0x90
_AddPeople:                             ## @AddPeople
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -56(%rbp)
	cmpq	$0, -56(%rbp)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movslq	%edx, %rax
	cmpq	$0, %rax
	je	LBB12_2
## %bb.1:
	leaq	L___func__.AddPeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$239, %edx
	callq	___assert_rtn
LBB12_2:
	jmp	LBB12_3
LBB12_3:
	movq	-56(%rbp), %rdi
	callq	_ContactIsFull
	cmpl	$0, %eax
	je	LBB12_5
## %bb.4:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.46(%rip), %rsi
	callq	_LogInfo
	leaq	-56(%rbp), %rdi
	callq	_IncContact
	movl	%eax, -60(%rbp)         ## 4-byte Spill
LBB12_5:
	movq	-56(%rbp), %rax
	addq	$8, %rax
	movq	-56(%rbp), %rcx
	movslq	4(%rcx), %rcx
	imulq	$143, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, %rdi
	callq	_GetPeopleInfo
	movl	$30, %edx
                                        ## kill: def %rdx killed %edx
	leaq	-48(%rbp), %rdi
	movq	l_AddPeople.msg(%rip), %rax
	movq	%rax, -48(%rbp)
	movq	l_AddPeople.msg+8(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	l_AddPeople.msg+16(%rip), %rax
	movq	%rax, -32(%rbp)
	movl	l_AddPeople.msg+24(%rip), %esi
	movl	%esi, -24(%rbp)
	movw	l_AddPeople.msg+28(%rip), %r8w
	movw	%r8w, -20(%rbp)
	movq	-56(%rbp), %rax
	addq	$8, %rax
	movq	-56(%rbp), %rcx
	movslq	4(%rcx), %rcx
	imulq	$143, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	callq	___strcat_chk
	leaq	L_.str.5(%rip), %rdi
	leaq	-48(%rbp), %rsi
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	callq	_LogInfo
	movq	-56(%rbp), %rax
	movl	4(%rax), %r9d
	addl	$1, %r9d
	movl	%r9d, 4(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB12_7
## %bb.6:                               ## %SP_return
	addq	$80, %rsp
	popq	%rbp
	retq
LBB12_7:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_GetPeopleInfo          ## -- Begin function GetPeopleInfo
	.p2align	4, 0x90
_GetPeopleInfo:                         ## @GetPeopleInfo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB13_2
## %bb.1:
	leaq	L___func__.GetPeopleInfo(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.47(%rip), %rcx
	movl	$255, %edx
	callq	___assert_rtn
LBB13_2:
	jmp	LBB13_3
LBB13_3:
	leaq	L_.str.48(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	movq	-8(%rbp), %rsi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.49(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$20, %rsi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.50(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$25, %rsi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.51(%rip), %rdi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$28, %rsi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str.52(%rip), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$43, %rsi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_SearchPeople           ## -- Begin function SearchPeople
	.p2align	4, 0x90
_SearchPeople:                          ## @SearchPeople
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -40(%rbp)
	cmpq	$0, -40(%rbp)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movslq	%edx, %rax
	cmpq	$0, %rax
	je	LBB14_2
## %bb.1:
	leaq	L___func__.SearchPeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$270, %edx              ## imm = 0x10E
	callq	___assert_rtn
LBB14_2:
	jmp	LBB14_3
LBB14_3:
	leaq	L_.str.53(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-32(%rbp), %rsi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movl	$0, -44(%rbp)
	movl	%eax, -52(%rbp)         ## 4-byte Spill
LBB14_4:                                ## =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	movq	-40(%rbp), %rcx
	cmpl	4(%rcx), %eax
	jge	LBB14_9
## %bb.5:                               ##   in Loop: Header=BB14_4 Depth=1
	xorl	%eax, %eax
	leaq	-32(%rbp), %rdi
	movq	-40(%rbp), %rcx
	addq	$8, %rcx
	movslq	-44(%rbp), %rdx
	imulq	$143, %rdx, %rdx
	addq	%rdx, %rcx
	movq	%rcx, %rsi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	callq	_strcmp
	movl	-56(%rbp), %r8d         ## 4-byte Reload
	cmpl	%eax, %r8d
	jne	LBB14_7
## %bb.6:                               ##   in Loop: Header=BB14_4 Depth=1
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movslq	-44(%rbp), %rcx
	imulq	$143, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, %rdi
	callq	_DispPeopleInfo
LBB14_7:                                ##   in Loop: Header=BB14_4 Depth=1
	jmp	LBB14_8
LBB14_8:                                ##   in Loop: Header=BB14_4 Depth=1
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB14_4
LBB14_9:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB14_11
## %bb.10:                              ## %SP_return
	addq	$64, %rsp
	popq	%rbp
	retq
LBB14_11:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_DispPeopleInfo         ## -- Begin function DispPeopleInfo
	.p2align	4, 0x90
_DispPeopleInfo:                        ## @DispPeopleInfo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB15_2
## %bb.1:
	leaq	L___func__.DispPeopleInfo(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.47(%rip), %rcx
	movl	$285, %edx              ## imm = 0x11D
	callq	___assert_rtn
LBB15_2:
	jmp	LBB15_3
LBB15_3:
	leaq	L_.str.54(%rip), %rdi
	movq	-8(%rbp), %rsi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.54(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$20, %rsi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.54(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$25, %rsi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.54(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$28, %rsi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.55(%rip), %rdi
	movq	-8(%rbp), %rsi
	addq	$43, %rsi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_NameCmpFun             ## -- Begin function NameCmpFun
	.p2align	4, 0x90
_NameCmpFun:                            ## @NameCmpFun
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rsi
	cmpq	$0, %rsi
	je	LBB16_2
## %bb.1:
	leaq	L___func__.NameCmpFun(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.56(%rip), %rcx
	movl	$300, %edx              ## imm = 0x12C
	callq	___assert_rtn
LBB16_2:
	jmp	LBB16_3
LBB16_3:
	cmpq	$0, -16(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdx
	cmpq	$0, %rdx
	je	LBB16_5
## %bb.4:
	leaq	L___func__.NameCmpFun(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.57(%rip), %rcx
	movl	$301, %edx              ## imm = 0x12D
	callq	___assert_rtn
LBB16_5:
	jmp	LBB16_6
LBB16_6:
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rsi
	callq	_strcmp
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_SortPeople             ## -- Begin function SortPeople
	.p2align	4, 0x90
_SortPeople:                            ## @SortPeople
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB17_2
## %bb.1:
	leaq	L___func__.SortPeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$309, %edx              ## imm = 0x135
	callq	___assert_rtn
LBB17_2:
	jmp	LBB17_3
LBB17_3:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.58(%rip), %rsi
	callq	_LogInfo
	movl	$143, %eax
	movl	%eax, %edx
	leaq	_NameCmpFun(%rip), %rcx
	movq	-8(%rbp), %rsi
	addq	$8, %rsi
	movq	-8(%rbp), %rdi
	movslq	4(%rdi), %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	callq	_qsort
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.59(%rip), %rsi
	callq	_LogInfo
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_DispAllPeople          ## -- Begin function DispAllPeople
	.p2align	4, 0x90
_DispAllPeople:                         ## @DispAllPeople
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB18_2
## %bb.1:
	leaq	L___func__.DispAllPeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$317, %edx              ## imm = 0x13D
	callq	___assert_rtn
LBB18_2:
	jmp	LBB18_3
LBB18_3:
	leaq	L_.str.60(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.61(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.62(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.63(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.64(%rip), %rdi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -12(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
LBB18_4:                                ## =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	4(%rcx), %eax
	jge	LBB18_7
## %bb.5:                               ##   in Loop: Header=BB18_4 Depth=1
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movslq	-12(%rbp), %rcx
	imulq	$143, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, %rdi
	callq	_DispPeopleInfo
## %bb.6:                               ##   in Loop: Header=BB18_4 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB18_4
LBB18_7:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_DeletePeople           ## -- Begin function DeletePeople
	.p2align	4, 0x90
_DeletePeople:                          ## @DeletePeople
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -40(%rbp)
	cmpq	$0, -40(%rbp)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movslq	%edx, %rax
	cmpq	$0, %rax
	je	LBB19_2
## %bb.1:
	leaq	L___func__.DeletePeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$331, %edx              ## imm = 0x14B
	callq	___assert_rtn
LBB19_2:
	jmp	LBB19_3
LBB19_3:
	movq	-40(%rbp), %rdi
	callq	_ContactIsEmpty
	cmpl	$0, %eax
	je	LBB19_5
## %bb.4:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.65(%rip), %rsi
	callq	_LogInfo
	jmp	LBB19_11
LBB19_5:
	leaq	L_.str.53(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-32(%rbp), %rsi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movl	$0, -44(%rbp)
	movl	%eax, -52(%rbp)         ## 4-byte Spill
LBB19_6:                                ## =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	movq	-40(%rbp), %rcx
	cmpl	4(%rcx), %eax
	jge	LBB19_11
## %bb.7:                               ##   in Loop: Header=BB19_6 Depth=1
	xorl	%eax, %eax
	leaq	-32(%rbp), %rdi
	movq	-40(%rbp), %rcx
	addq	$8, %rcx
	movslq	-44(%rbp), %rdx
	imulq	$143, %rdx, %rdx
	addq	%rdx, %rcx
	movq	%rcx, %rsi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	callq	_strcmp
	movl	-56(%rbp), %r8d         ## 4-byte Reload
	cmpl	%eax, %r8d
	jne	LBB19_9
## %bb.8:                               ##   in Loop: Header=BB19_6 Depth=1
	movl	$143, %eax
	movl	%eax, %edx
	movq	$-1, %rcx
	movq	-40(%rbp), %rsi
	addq	$8, %rsi
	movslq	-44(%rbp), %rdi
	imulq	$143, %rdi, %rdi
	addq	%rdi, %rsi
	movq	-40(%rbp), %rdi
	addq	$8, %rdi
	movq	-40(%rbp), %r8
	movl	4(%r8), %eax
	subl	$1, %eax
	movslq	%eax, %r8
	imulq	$143, %r8, %r8
	addq	%r8, %rdi
	movq	%rdi, -64(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	callq	___memcpy_chk
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.66(%rip), %rsi
	movq	-40(%rbp), %rcx
	movl	4(%rcx), %r9d
	addl	$-1, %r9d
	movl	%r9d, 4(%rcx)
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	callq	_LogInfo
LBB19_9:                                ##   in Loop: Header=BB19_6 Depth=1
	jmp	LBB19_10
LBB19_10:                               ##   in Loop: Header=BB19_6 Depth=1
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB19_6
LBB19_11:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB19_13
## %bb.12:                              ## %SP_return
	addq	$80, %rsp
	popq	%rbp
	retq
LBB19_13:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_StrToLower             ## -- Begin function StrToLower
	.p2align	4, 0x90
_StrToLower:                            ## @StrToLower
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdi
	cmpq	$0, %rdi
	je	LBB20_2
## %bb.1:
	leaq	L___func__.StrToLower(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.67(%rip), %rcx
	movl	$355, %edx              ## imm = 0x163
	callq	___assert_rtn
LBB20_2:
	jmp	LBB20_3
LBB20_3:
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
LBB20_4:                                ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	cmpb	$0, (%rax)
	je	LBB20_6
## %bb.5:                               ##   in Loop: Header=BB20_4 Depth=1
	movq	-8(%rbp), %rax
	movsbl	(%rax), %edi
	callq	_tolower
	movb	%al, %cl
	movq	-8(%rbp), %rdx
	movb	%cl, (%rdx)
	movq	-8(%rbp), %rdx
	addq	$1, %rdx
	movq	%rdx, -8(%rbp)
	jmp	LBB20_4
LBB20_6:
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ClearAllPeople         ## -- Begin function ClearAllPeople
	.p2align	4, 0x90
_ClearAllPeople:                        ## @ClearAllPeople
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	cmpq	$0, -40(%rbp)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movslq	%edx, %rax
	cmpq	$0, %rax
	je	LBB21_2
## %bb.1:
	leaq	L___func__.ClearAllPeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$367, %edx              ## imm = 0x16F
	callq	___assert_rtn
LBB21_2:
	jmp	LBB21_3
LBB21_3:
	cmpq	$0, -48(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdx
	cmpq	$0, %rdx
	je	LBB21_5
## %bb.4:
	leaq	L___func__.ClearAllPeople(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.12(%rip), %rcx
	movl	$368, %edx              ## imm = 0x170
	callq	___assert_rtn
LBB21_5:
	jmp	LBB21_6
LBB21_6:
	leaq	L_.str.68(%rip), %rdi
	leaq	L_.str.69(%rip), %rsi
	callq	_LogInfo
	leaq	L_.str.70(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-53(%rbp), %rsi
	xorl	%ecx, %ecx
	movl	$5, %edx
                                        ## kill: def %rdx killed %edx
	movq	%rsi, %r8
	movq	%rdi, -64(%rbp)         ## 8-byte Spill
	movq	%r8, %rdi
	movq	%rsi, -72(%rbp)         ## 8-byte Spill
	movl	%ecx, %esi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	callq	_memset
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	-72(%rbp), %rsi         ## 8-byte Reload
	movb	$0, %al
	callq	_scanf
	leaq	-53(%rbp), %rdi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	callq	_StrToLower
	xorl	%ecx, %ecx
	leaq	-53(%rbp), %rdi
	leaq	L_.str.71(%rip), %rsi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	movl	%ecx, -92(%rbp)         ## 4-byte Spill
	callq	_strcmp
	movl	-92(%rbp), %ecx         ## 4-byte Reload
	cmpl	%eax, %ecx
	jne	LBB21_11
## %bb.7:
	leaq	L_.str.27(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.23(%rip), %rdi
	leaq	-32(%rbp), %rsi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	xorl	%ecx, %ecx
	leaq	-32(%rbp), %rdi
	movq	-48(%rbp), %rsi
	addq	$20, %rsi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	movl	%ecx, -104(%rbp)        ## 4-byte Spill
	callq	_strcmp
	movl	-104(%rbp), %ecx        ## 4-byte Reload
	cmpl	%eax, %ecx
	jne	LBB21_9
## %bb.8:
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.72(%rip), %rsi
	movq	-40(%rbp), %rax
	movl	$0, 4(%rax)
	callq	_LogInfo
	jmp	LBB21_10
LBB21_9:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.29(%rip), %rsi
	callq	_LogInfo
	jmp	LBB21_12
LBB21_10:
	jmp	LBB21_12
LBB21_11:
	jmp	LBB21_12
LBB21_12:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB21_14
## %bb.13:                              ## %SP_return
	addq	$112, %rsp
	popq	%rbp
	retq
LBB21_14:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_SaveToFile             ## -- Begin function SaveToFile
	.p2align	4, 0x90
_SaveToFile:                            ## @SaveToFile
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rsi
	cmpq	$0, %rsi
	je	LBB22_2
## %bb.1:
	leaq	L___func__.SaveToFile(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$404, %edx              ## imm = 0x194
	callq	___assert_rtn
LBB22_2:
	jmp	LBB22_3
LBB22_3:
	cmpq	$0, -16(%rbp)
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %ecx
	movslq	%ecx, %rdx
	cmpq	$0, %rdx
	je	LBB22_5
## %bb.4:
	leaq	L___func__.SaveToFile(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.12(%rip), %rcx
	movl	$405, %edx              ## imm = 0x195
	callq	___assert_rtn
LBB22_5:
	jmp	LBB22_6
LBB22_6:
	movq	-16(%rbp), %rdi
	callq	_GetFileName
	leaq	L_.str.73(%rip), %rsi
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
	callq	_fopen
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB22_8
## %bb.7:
	leaq	L_.str.26(%rip), %rdi
	leaq	L_.str.74(%rip), %rsi
	callq	_LogInfo
	jmp	LBB22_9
LBB22_8:
	movl	$1, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rcx
	movq	-8(%rbp), %rsi
	movslq	4(%rsi), %rsi
	imulq	$143, %rsi, %rsi
	addq	$8, %rsi
	movq	-32(%rbp), %rdi
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	movq	-40(%rbp), %rcx         ## 8-byte Reload
	callq	_fwrite
	leaq	L_.str.5(%rip), %rdi
	leaq	L_.str.75(%rip), %rsi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	callq	_LogInfo
	movq	-32(%rbp), %rdi
	callq	_fclose
	movl	%eax, -52(%rbp)         ## 4-byte Spill
LBB22_9:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L___func__.LogInfo:                     ## @__func__.LogInfo
	.asciz	"LogInfo"

L_.str:                                 ## @.str
	.asciz	"contact.c"

L_.str.1:                               ## @.str.1
	.asciz	"leval"

L_.str.2:                               ## @.str.2
	.asciz	"msg"

L_.str.3:                               ## @.str.3
	.asciz	"#%s:%s\n"

L___func__.ContactIsFull:               ## @__func__.ContactIsFull
	.asciz	"ContactIsFull"

L_.str.4:                               ## @.str.4
	.asciz	"pct"

L___func__.ContactIsEmpty:              ## @__func__.ContactIsEmpty
	.asciz	"ContactIsEmpty"

L_.str.5:                               ## @.str.5
	.asciz	"INFO"

L_.str.6:                               ## @.str.6
	.asciz	"\351\200\232\350\256\257\345\275\225 V2.0"

L_.str.7:                               ## @.str.7
	.asciz	"########################\n"

L_.str.8:                               ## @.str.8
	.asciz	"####   0.  \351\200\200\345\207\272     ####\n"

L_.str.9:                               ## @.str.9
	.asciz	"####   1.  \347\231\273\351\231\206     ####\n"

L_.str.10:                              ## @.str.10
	.asciz	"####   2.  \346\263\250\345\206\214     ####\n"

L_.str.11:                              ## @.str.11
	.asciz	">"

L___func__.MainMenu:                    ## @__func__.MainMenu
	.asciz	"MainMenu"

L_.str.12:                              ## @.str.12
	.asciz	"pu"

	.section	__TEXT,__const
	.p2align	4               ## @MainMenu.msg
l_MainMenu.msg:
	.asciz	"\345\275\223\345\211\215\347\224\250\346\210\267\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L_.str.13:                              ## @.str.13
	.asciz	"##############################\n"

L_.str.14:                              ## @.str.14
	.asciz	"####  0.  \351\200\200\345\207\272            ####\n"

L_.str.15:                              ## @.str.15
	.asciz	"####  1.  \346\267\273\345\212\240\350\201\224\347\263\273\344\272\272      ####\n"

L_.str.16:                              ## @.str.16
	.asciz	"####  2.  \346\237\245\346\211\276\350\201\224\347\263\273\344\272\272      ####\n"

L_.str.17:                              ## @.str.17
	.asciz	"####  3.  \346\216\222\345\272\217\350\201\224\347\263\273\344\272\272      ####\n"

L_.str.18:                              ## @.str.18
	.asciz	"####  4.  \345\210\240\351\231\244\350\201\224\347\263\273\344\272\272      ####\n"

L_.str.19:                              ## @.str.19
	.asciz	"####  5.  \345\210\227\345\207\272\346\211\200\346\234\211\350\201\224\347\263\273\344\272\272  ####\n"

L_.str.20:                              ## @.str.20
	.asciz	"####  6.  \346\270\205\347\251\272\346\211\200\346\234\211\350\201\224\347\263\273\344\272\272  ####\n"

L___func__.GetFileName:                 ## @__func__.GetFileName
	.asciz	"GetFileName"

L_.str.21:                              ## @.str.21
	.asciz	".txt"

L_.str.22:                              ## @.str.22
	.asciz	"\347\224\250\346\210\267\345\220\215>"

L_.str.23:                              ## @.str.23
	.asciz	"%s"

L_.str.24:                              ## @.str.24
	.asciz	"r"

	.section	__TEXT,__const
	.p2align	4               ## @UserLogin.msg
l_UserLogin.msg:
	.asciz	"\347\224\250\346\210\267\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L_.str.25:                              ## @.str.25
	.asciz	"\344\270\215\345\255\230\345\234\250"

L_.str.26:                              ## @.str.26
	.asciz	"ERROR"

L_.str.27:                              ## @.str.27
	.asciz	"\345\257\206\347\240\201>"

	.section	__TEXT,__const
	.p2align	4               ## @UserLogin.msg.28
l_UserLogin.msg.28:
	.asciz	"\346\254\242\350\277\216\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L_.str.29:                              ## @.str.29
	.asciz	"\345\257\206\347\240\201\351\224\231\350\257\257"

	.section	__TEXT,__const
	.p2align	4               ## @UserRegist.msg
l_UserRegist.msg:
	.asciz	"\347\224\250\346\210\267\345\220\215\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L_.str.30:                              ## @.str.30
	.asciz	"\345\267\262\350\242\253\346\263\250\345\206\214"

L_.str.31:                              ## @.str.31
	.asciz	"a+"

L_.str.32:                              ## @.str.32
	.asciz	"\345\210\233\345\273\272\347\224\250\346\210\267\346\226\207\344\273\266\345\244\261\350\264\245\357\274\214\350\257\267\346\243\200\346\237\245\345\275\223\345\211\215\347\233\256\345\275\225\346\235\203\351\231\220"

L_.str.33:                              ## @.str.33
	.asciz	"\346\263\250\345\206\214\346\210\220\345\212\237"

L_.str.34:                              ## @.str.34
	.asciz	"%d"

L_.str.35:                              ## @.str.35
	.asciz	"\345\206\215\350\247\201"

L_.str.36:                              ## @.str.36
	.asciz	"\350\276\223\345\205\245\346\234\211\350\257\257"

L___func__.ContactInit:                 ## @__func__.ContactInit
	.asciz	"ContactInit"

L_.str.37:                              ## @.str.37
	.asciz	"\345\210\235\345\247\213\345\214\226\351\200\232\350\256\257\345\275\225\345\244\261\350\264\245\357\274\214\345\210\206\351\205\215\351\200\232\350\256\257\345\275\225\347\251\272\351\227\264\345\244\261\350\264\245"

L_.str.38:                              ## @.str.38
	.asciz	"\346\255\243\345\234\250\345\210\233\345\273\272\345\275\223\345\211\215\347\224\250\346\210\267\347\232\204\351\200\232\350\256\257\345\275\225\346\226\207\344\273\266"

L_.str.39:                              ## @.str.39
	.asciz	"wb+"

L_.str.40:                              ## @.str.40
	.asciz	"\345\210\233\345\273\272\346\226\207\344\273\266\345\244\261\350\264\245"

L_.str.41:                              ## @.str.41
	.asciz	"\345\210\233\345\273\272\345\275\223\345\211\215\347\224\250\346\210\267\347\232\204\351\200\232\350\256\257\345\275\225\346\226\207\344\273\266\346\210\220\345\212\237"

L_.str.42:                              ## @.str.42
	.asciz	"\345\210\206\351\205\215\347\251\272\351\227\264\345\244\261\350\264\245"

L___func__.IncContact:                  ## @__func__.IncContact
	.asciz	"IncContact"

L_.str.43:                              ## @.str.43
	.asciz	"ppct"

L_.str.44:                              ## @.str.44
	.asciz	"\346\211\251\345\256\271\345\244\261\350\264\245"

L_.str.45:                              ## @.str.45
	.asciz	"\346\211\251\345\256\271\346\210\220\345\212\237"

L___func__.AddPeople:                   ## @__func__.AddPeople
	.asciz	"AddPeople"

L_.str.46:                              ## @.str.46
	.asciz	"\351\200\232\350\256\257\345\275\225\345\267\262\346\273\241\357\274\214\346\255\243\345\234\250\346\211\251\345\256\271"

	.section	__TEXT,__const
	.p2align	4               ## @AddPeople.msg
l_AddPeople.msg:
	.asciz	"\345\267\262\346\267\273\345\212\240\350\201\224\347\263\273\344\272\272\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L___func__.GetPeopleInfo:               ## @__func__.GetPeopleInfo
	.asciz	"GetPeopleInfo"

L_.str.47:                              ## @.str.47
	.asciz	"pp"

L_.str.48:                              ## @.str.48
	.asciz	"\345\247\223\345\220\215>"

L_.str.49:                              ## @.str.49
	.asciz	"\346\200\247\345\210\253>"

L_.str.50:                              ## @.str.50
	.asciz	"\345\271\264\351\276\204>"

L_.str.51:                              ## @.str.51
	.asciz	"\347\224\265\350\257\235>"

L_.str.52:                              ## @.str.52
	.asciz	"\344\275\217\345\235\200>"

L___func__.SearchPeople:                ## @__func__.SearchPeople
	.asciz	"SearchPeople"

L_.str.53:                              ## @.str.53
	.asciz	"\350\246\201\346\237\245\346\211\276\347\232\204\350\201\224\347\263\273\344\272\272\345\247\223\345\220\215>"

L___func__.DispPeopleInfo:              ## @__func__.DispPeopleInfo
	.asciz	"DispPeopleInfo"

L_.str.54:                              ## @.str.54
	.asciz	"|%s\t\t"

L_.str.55:                              ## @.str.55
	.asciz	"|%s\t\t|\n"

L___func__.NameCmpFun:                  ## @__func__.NameCmpFun
	.asciz	"NameCmpFun"

L_.str.56:                              ## @.str.56
	.asciz	"n1"

L_.str.57:                              ## @.str.57
	.asciz	"n2"

L___func__.SortPeople:                  ## @__func__.SortPeople
	.asciz	"SortPeople"

L_.str.58:                              ## @.str.58
	.asciz	"\346\255\243\345\234\250\346\214\211\345\247\223\345\220\215\346\216\222\345\272\217\346\211\200\346\234\211\350\201\224\347\263\273\344\272\272"

L_.str.59:                              ## @.str.59
	.asciz	"\346\216\222\345\272\217\345\256\214\346\210\220"

L___func__.DispAllPeople:               ## @__func__.DispAllPeople
	.asciz	"DispAllPeople"

L_.str.60:                              ## @.str.60
	.asciz	"|\345\247\223\345\220\215\t\t|"

L_.str.61:                              ## @.str.61
	.asciz	"\346\200\247\345\210\253\t\t|"

L_.str.62:                              ## @.str.62
	.asciz	"\345\271\264\351\276\204\t\t|"

L_.str.63:                              ## @.str.63
	.asciz	"\347\224\265\350\257\235\t\t|"

L_.str.64:                              ## @.str.64
	.asciz	"\344\275\217\345\235\200\t\t|\n"

L___func__.DeletePeople:                ## @__func__.DeletePeople
	.asciz	"DeletePeople"

L_.str.65:                              ## @.str.65
	.asciz	"\351\200\232\350\256\257\345\275\225\344\270\272\347\251\272"

L_.str.66:                              ## @.str.66
	.asciz	"\345\210\240\351\231\244\346\210\220\345\212\237"

L___func__.StrToLower:                  ## @__func__.StrToLower
	.asciz	"StrToLower"

L_.str.67:                              ## @.str.67
	.asciz	"str"

L___func__.ClearAllPeople:              ## @__func__.ClearAllPeople
	.asciz	"ClearAllPeople"

L_.str.68:                              ## @.str.68
	.asciz	"WARNING"

L_.str.69:                              ## @.str.69
	.asciz	"\347\241\256\345\256\232?"

L_.str.70:                              ## @.str.70
	.asciz	"(yes/no)>"

L_.str.71:                              ## @.str.71
	.asciz	"yes"

L_.str.72:                              ## @.str.72
	.asciz	"\346\270\205\347\251\272\346\210\220\345\212\237"

L___func__.SaveToFile:                  ## @__func__.SaveToFile
	.asciz	"SaveToFile"

L_.str.73:                              ## @.str.73
	.asciz	"rb"

L_.str.74:                              ## @.str.74
	.asciz	"\344\277\235\345\255\230\346\226\207\344\273\266\350\277\207\347\250\213\344\270\255\357\274\214\346\211\223\345\274\200\346\226\207\344\273\266\345\244\261\350\264\245"

L_.str.75:                              ## @.str.75
	.asciz	"\346\226\207\344\273\266\344\277\235\345\255\230\346\210\220\345\212\237"

L___func__.MainCtrl:                    ## @__func__.MainCtrl
	.asciz	"MainCtrl"


.subsections_via_symbols
