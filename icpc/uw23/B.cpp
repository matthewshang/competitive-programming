// s=1, t=2
// - F S A -> s=(1,0), t=(0,0)
//   - P S T -> s=(0,0), t=(1,0)
//     - F T A -> s=(0,0), t=(2,0)
//     - F T B -> s=(0,0), t=(1,1)
//     - F S A -> s=(1,0), t=(1,0)

/* achieve 1/2:
 * Fill S with A, Pour S into T, Fill T with B -> t=(1, 1)
 * Pour T into S, Empty T, Pour S into T -> t=(1/2, 1/2)
 * Fill T with B -> t=(1/2, 3/2)
 * Pour T into S, Empty T, Pour S into T -> t=(1/4, 3/4)
 * Fill T with A -> t=(5/4, 3/4)
 * Pout T into S, Empty T, Pour S into T -> t=(5/8, 3/8)
 * Fill T with B -> t=(5/8, 11/8)
 * 
 * From (a/2^k, (2^k+1 - a)/2^k) in T, we can get ((a + 2^k+1)/2^k+1, (2^k+1 - a)/2^k+1) or (a/2^k+1, (2^k+2 - a)/2^k+1) in T
 */

// max s = 1, max t = 2
// s = (A_S, B_S), t = (A_T, B_T)
// * F S A : s -> (1 - B_S, B_S)
// * F S B : s -> (A_S, 1 - A_S)
// * F T A : t -> (2 - B_T, B_T)
// * F T B : t -> (A_T, 2 - A_T)
// * P S T : l = min(1, 2 - A_T - B_T), t -> (l * A_S + A_T, l * B_S + B_T), s -> (A_S * (1 - l), B_S * (1 - l))
// * 