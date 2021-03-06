 # #   C 1 
 #   V o l u m u l   u n u i   e l i p s o i d   ( d e   r e v o l u t i e ) 
 #   E ( a ,   b ,   c )   =   { ( u ,   v ,   w )   :   ( u ^ 2 ) / ( a ^ 2 ) + ( v ^ 2 ) / ( b ^ 2 ) + ( w ^ 2 ) / ( c ^ 2 )   < =   1 }  "�   [" a ,   a ]   �   [" b ,   b ]   �   [" c ,   c ] 
 #   e s t e   ( 4� / 3 ) * a b c .   E s t i m a t i   a c e s t   v o l u m   u t i l i z a n d   m e t o d a   M o n t e   C a r l o   p e n t r u   a   =   2 ,   b   =   3 ,   c   =   4   s i   c o m p a r a t i   
 #   r e z u l t a t u l   c u   v a l o a r e a   e x a c t a .   F o l o s i t i   e s a n t i o a n e   d e   d i m e n s i u n e   1 0 0 0 0 ,   2 0 0 0 0   s i   5 0 0 0 0   t r i a l s   s i   
 #   c a l c u l a t i   e r o r i l e   r e l a t i v e . 
 
 #   E ( 2 ,   3 ,   4 )   =   { ( u ,   v ,   w )   :   ( u ^ 2 ) / 4 + ( v ^ 2 ) / 9 + ( w ^ 2 ) / 1 6   < =   1 }  "�   [" 2 , 2 ]   �   [" 3 ,   3 ]   �   [" 4 ,   4 ] 
 
 v o l u m _ e l i p s o i d _ d e _ r e v o l u t i e = f u n c t i o n ( N ) 
 { 
     N _ C = 0 ; 
     f o r ( i   i n   1 : N ) 
     { 
         x = r u n i f ( 1 , - 2 , 2 ) ; 
         y = r u n i f ( 1 , - 3 , 3 ) ; 
         z = r u n i f ( 1 , - 4 , 4 ) ; 
         i f ( ( x * x / 4 ) + ( y * y / 9 ) + ( z * z / 1 6 ) < = 1 )   N _ C = N _ C + 1 ; 
     } 
     r e t u r n   ( 8 * 6 * 4 * N _ C / N ) ; 
 } 
 
 v o l u m _ e l i p s o i d _ d e _ r e v o l u t i e ( 1 0 0 0 0 ) 
 v o l u m _ e l i p s o i d _ d e _ r e v o l u t i e ( 2 0 0 0 0 ) 
 v o l u m _ e l i p s o i d _ d e _ r e v o l u t i e ( 5 0 0 0 0 ) 
 
 # #   C 3 
 #   E s t i m a t i   v a l o a r i l e   u r m a t o a r e l o r   i n t e g r a l e   s i   c o m p a r a t i   r e z u l t a t u l   c u   v a l o r i l e   e x a c t e   ( d a c a   s u n t   d a t e ) : 
 #   ( a )   i n t e g r a l a   d e   l a   0   l a   1   d i n   [ c o s   ( 5 0 x )   +   s i n   ( 2 0 x ) ] ^ 2   d x 
 #   ( b )   i n t e g r a l a   d e   l a   0   l a   3   d i n   ( x ^ 3 ) / ( x ^ 4 + 1 )   d x   =   1 . 0 1 1 6 8 ; 
 
 i n t e g r a t i o n _ a = f u n c t i o n ( N ) 
 { 
     s = 0 ; 
     f o r ( i   i n   1 : N ) 
     { 
         u = r u n i f ( 1 , 0 , 1 ) ; 
         s i = s i n ( 2 0 * u ) ; 
         c o = c o s ( 5 0 * u ) ; 
         s = s + ( c o + s i ) * ( c o + s i ) ; 
     } 
     r e t u r n   ( s / N ) ; 
 } 
 
 i n t e g r a t i o n _ a ( 1 0 0 0 0 ) 
 i n t e g r a t i o n _ a ( 2 0 0 0 0 ) 
 i n t e g r a t i o n _ a ( 5 0 0 0 0 ) 
 
 i n t e g r a t i o n _ b = f u n c t i o n ( N ) 
 { 
     s = 0 ; 
     f o r ( i   i n   1 : N ) 
     { 
         x = r u n i f ( 1 , 0 , 3 ) ; 
         s = s + ( x ^ 3 ) / ( x ^ 4 + 1 ) ; 
     } 
     r e t u r n   ( 3 * s / N ) ; 
 } 
 
 i n t e g r a t i o n _ b ( 1 0 0 0 0 ) 
 i n t e g r a t i o n _ b ( 2 0 0 0 0 ) 
 i n t e g r a t i o n _ b ( 5 0 0 0 0 ) 
 
 # #   C 4 
 #   T r e i   s e r v e r e   w e b   o f e r a   a c e l e a s i   p a g i n i   p o s i b i l i l o r   c l i e n t i   ( w e b ) . 
 #   T i m p u l   n e c e s a r   p r o c e s a r i i   u n e i   c e r e r i   H T T P   e s t e   d i s t r i b u i t  � ( 5 ,   3 )   p e   p r i m u l   s e r v e r ,  � ( 7 ,   5 )   p e   c e l   d e - a l   
 #   d o i l e a   s i  � ( 5 ,   2 )   p e   a l   t r e i l e a   ( i n   m i l i s e c u n d e ) .   L a   a c e a s t a   d u r a t a   s e   a d a u g a   l a t e n t a   d i n t r e   c l i e n t   s i   
 #   s e r v e r e   p e   I n t e r n e t   c a r e   a r e   o   d i s t r i b u t i e   e x p o n e n t i a l a   c u  �   =   1   ( i n   m i l i s e c u n d e ) .   S e   s t i e   c a   u n   c l i e n t   
 #   e s t e   d i r e c t i o n a t   c a t r e   p r i m u l   s e r v e r   c u   p r o b a b i l i t a t e a   0 . 5   s i   c a t r e   a l   d o i l e a   s e r v e r   c u   p r o b a b i l i t a t e a   0 . 3 .   
 #   E s t i m a t i   t i m p u l   m e d i u   n e c e s a r   s e r v i r i i   u n u i   c l i e n t   ( d e   l a   l a n s a r e a   c e r e r i i   p a n a   l a   p r i m i r e a   r a s p u n s u l u i ) . 
 
 r e t e a   =   f u n c t i o n ( N ) 
 { 
     s   =   0 ; 
     f o r ( i   i n   1 : N )   { 
         x   =   r e x p ( 1 , 1 ) ; 
         g 1   =   r g a m m a ( 1 ,   s h a p e = 5 ,   s c a l e = 3 ) ; 
         g 2   =   r g a m m a ( 1 ,   s h a p e = 7 ,   s c a l e = 5 ) ; 
         g 3   =   r g a m m a ( 1 ,   s h a p e = 5 ,   s c a l e = 2 ) ; 
         u   =   r u n i f ( 1 , 0 , 1 ) ; 
         i f ( u   < =   0 . 5 )   s   =   s + g 1 
         e l s e 
         { 
             i f ( u   >   0 . 8 )   s   =   s + g 3 
             e l s e   s   =   s + g 2 
         } 
         s   =   s + x 
     } 
     r e t u r n   ( s / N ) 
 } 
 
 r e t e a ( 5 0 0 0 0 ) 
 
 # #   C 7 
 #   2 0   d e   s t u d e n t i   a u   c o n t u r i   p e   u n   a c e l a s i   s e r v e r   d e   m a i l .   C o n t u l   u n u l   s t u d e n t   e s t e   i n f e c t a t   d e   u n   
 #   m a l w a r e .   I n   f i e c a r e   z i ,   a c e s t   m a l w a r e   s e   r a s p a n d e s t e   s i   a j u n g e   d e   l a   u n   c o n t   i n f e c t a t   l a   u n u l   n e i n f e c t a t   
 #   c u   p r o b a b i l i t a t e   0 . 2 5 .   D e   a s e m e n i ,   i n   f i e c a r e   z i   (1 n c e p a n d   c u   a   d o u a   z i ) ,   a d m i n i s t r a t o r u l   d e   s i s t e m   c u r a t a   
 #   l a   i n t a m p l a r e   5   c o n t u r i   ( s a u   t o a t e   c o n t u r i l e   d a c a   s u n t   i n f e c t a t e   m a i   p u t i n   d e   5 ) . 
 #   ( a )   E s t i m a t i   p r o b a b i l i t a t e a   c a   f i e c a r e   c o n t   s a   f i e   i n f e c t a t   c e l   p u t i n   o   d a t a . 
 #   ( b )   E s t i m a t i   p r o b a b i l i t a t e a   c a   i n t r - o   a n u m i t a   z i   t o a t e   c o n t u r i l e   s a   f i e   i n f e c t a t e . 
 #   ( c )   C a t   d e   m a r e   t r e b u i e   s a   f i e   n u m a r u l   d e   s i m u l a r i   -   a d i c a   d i m e n s i u n e a   e s a n t i o n u l u i   -   a s t f e l   c a   p r i m a   
 #   p r o b a b i l i t a t e   s a   a i b a   o   e r o a r e   d e   c e l   m u l t   � 0 . 0 1   c u   p r o b a b i l i t a t e a   0 . 9 9 ?   G a s i t i   o   a s t f e l   d e   e s t i m a r e . 
 
 #   a ) 
 c o n t u r i   =   f u n c t i o n ( ) 
 { 
     n r _ d a y s = 1 ; 
     p = 0 . 2 5 ; 
     n r = 1 9 ; 
     n r = n r - r b i n o m ( 1 ,   1 9 ,   0 . 2 5 ) ; 
     p r i n t ( n r ) ; 
     w h i l e ( n r > 0   &   n r < 2 0 ) 
     { 
         n r _ d a y s = n r _ d a y s + 1 ; 
         p = 1 - 0 . 7 5 ^ ( 2 0 - n r ) ; 
         c = r b i n o m ( 1 ,   n r ,   p ) ; 
         n r = n r - c + 5 ; 
     } 
     r e t u r n   ( n r ) ; 
 } 
 
 c o n t u r i ( ) 
 
 #   b ) 
 t o a t e c o n t u r i l e   =   f u n c t i o n ( N ) 
 { 
     s u m = 0 ; 
     f o r ( i   i n   1 : N ) 
     { 
         i f ( c o n t u r i ( ) > = 2 0 )   s u m = s u m + 1 ; 
     } 
     r e t u r n   ( s u m / N ) ; 
 } 
 
 t o a t e c o n t u r i l e ( 5 0 0 0 0 ) 
 
 #   c ) 
 e s t i m a t e d _ e r r o r _ p r o b l   =   f u n c t i o n ( p ,   p r ,   e p s i l o n )   
 { 
     a l f a   =   1 - p r ; 
     z   =   q n o r m ( a l f a / 2 ) ; 
     N _ m i n   =   ( 1 - p ) * p * ( z / e p s i l o n ) ^ 2 ; 
     p r i n t ( N _ m i n ) 
 } 
 
 e s t i m a t e d _ e r r o r _ p r o b l ( 0 . 2 7 ,   0 . 9 9 ,   0 . 0 1 )