(set-option :produce-models true)
(declare-datatypes () ((Col x0 x1 x2 x3 x4 x5 x6 x7 x8)))
(declare-datatypes () ((Row y0 y1 y2 y3 y4 y5 y6 y7 y8)))
(declare-fun Board (Col Row) Int)


; Fill in the missing constraints into the designated sections

;;;;;; --- BEGIN-CONSTRAINTS-1 --- 

; ** Sudoku constraints **

; Pre-defined cell values given in the problem statement

; Top-left
(assert (= (Board x1 y1) 5))
(assert (= (Board x2 y1) 1))

; Top-mid
(assert (= (Board x5 y0) 5))
(assert (= (Board x4 y1) 7))
(assert (= (Board x3 y2) 6))

; Mid-left
(assert (= (Board x1 y4) 9))

; Mid-center
(assert (= (Board x3 y3) 4))

; Mid-right
(assert (= (Board x6 y3) 6))

; Bottom-mid
(assert (= (Board x3 y6) 3))
(assert (= (Board x4 y6) 8))
(assert (= (Board x4 y8) 2))

; Bottom-right
(assert (= (Board x8 y7) 2))
(assert (= (Board x7 y8) 6))

; Constraint that numbers can't be repeated in a row, column or 3x3 square

; Constraint for the rows
(assert
    (distinct 
        (Board x0 y0)
        (Board x0 y1)
        (Board x0 y2)
        (Board x0 y3)
        (Board x0 y4)
        (Board x0 y5)
        (Board x0 y6)
        (Board x0 y7)
        (Board x0 y8)
    )
)
(assert
    (distinct 
        (Board x1 y0)
        (Board x1 y1)
        (Board x1 y2)
        (Board x1 y3)
        (Board x1 y4)
        (Board x1 y5)
        (Board x1 y6)
        (Board x1 y7)
        (Board x1 y8)
    )
)
(assert
    (distinct 
        (Board x2 y0)
        (Board x2 y1)
        (Board x2 y2)
        (Board x2 y3)
        (Board x2 y4)
        (Board x2 y5)
        (Board x2 y6)
        (Board x2 y7)
        (Board x2 y8)
    )
)
(assert
    (distinct 
        (Board x3 y0)
        (Board x3 y1)
        (Board x3 y2)
        (Board x3 y3)
        (Board x3 y4)
        (Board x3 y5)
        (Board x3 y6)
        (Board x3 y7)
        (Board x3 y8)
    )
)
(assert
    (distinct 
        (Board x4 y0)
        (Board x4 y1)
        (Board x4 y2)
        (Board x4 y3)
        (Board x4 y4)
        (Board x4 y5)
        (Board x4 y6)
        (Board x4 y7)
        (Board x4 y8)
    )
)
(assert
    (distinct 
        (Board x5 y0)
        (Board x5 y1)
        (Board x5 y2)
        (Board x5 y3)
        (Board x5 y4)
        (Board x5 y5)
        (Board x5 y6)
        (Board x5 y7)
        (Board x5 y8)
    )
)
(assert
    (distinct 
        (Board x6 y0)
        (Board x6 y1)
        (Board x6 y2)
        (Board x6 y3)
        (Board x6 y4)
        (Board x6 y5)
        (Board x6 y6)
        (Board x6 y7)
        (Board x6 y8)
    )
)
(assert
    (distinct 
        (Board x7 y0)
        (Board x7 y1)
        (Board x7 y2)
        (Board x7 y3)
        (Board x7 y4)
        (Board x7 y5)
        (Board x7 y6)
        (Board x7 y7)
        (Board x7 y8)
    )
)
(assert
    (distinct 
        (Board x8 y0)
        (Board x8 y1)
        (Board x8 y2)
        (Board x8 y3)
        (Board x8 y4)
        (Board x8 y5)
        (Board x8 y6)
        (Board x8 y7)
        (Board x8 y8)
    )
)

; Constraints for the columns
(assert
    (distinct 
        (Board x0 y0)
        (Board x1 y0)
        (Board x2 y0)
        (Board x3 y0)
        (Board x4 y0)
        (Board x5 y0)
        (Board x6 y0)
        (Board x7 y0)
        (Board x8 y0)
    )
)
(assert
    (distinct 
        (Board x0 y1)
        (Board x1 y1)
        (Board x2 y1)
        (Board x3 y1)
        (Board x4 y1)
        (Board x5 y1)
        (Board x6 y1)
        (Board x7 y1)
        (Board x8 y1)
    )
)
(assert
    (distinct 
        (Board x0 y2)
        (Board x1 y2)
        (Board x2 y2)
        (Board x3 y2)
        (Board x4 y2)
        (Board x5 y2)
        (Board x6 y2)
        (Board x7 y2)
        (Board x8 y2)
    )
)
(assert
    (distinct 
        (Board x0 y3)
        (Board x1 y3)
        (Board x2 y3)
        (Board x3 y3)
        (Board x4 y3)
        (Board x5 y3)
        (Board x6 y3)
        (Board x7 y3)
        (Board x8 y3)
    )
)
(assert
    (distinct 
        (Board x0 y4)
        (Board x1 y4)
        (Board x2 y4)
        (Board x3 y4)
        (Board x4 y4)
        (Board x5 y4)
        (Board x6 y4)
        (Board x7 y4)
        (Board x8 y4)
    )
)
(assert
    (distinct 
        (Board x0 y5)
        (Board x1 y5)
        (Board x2 y5)
        (Board x3 y5)
        (Board x4 y5)
        (Board x5 y5)
        (Board x6 y5)
        (Board x7 y5)
        (Board x8 y5)
    )
)
(assert
    (distinct 
        (Board x0 y6)
        (Board x1 y6)
        (Board x2 y6)
        (Board x3 y6)
        (Board x4 y6)
        (Board x5 y6)
        (Board x6 y6)
        (Board x7 y6)
        (Board x8 y6)
    )
)
(assert
    (distinct 
        (Board x0 y7)
        (Board x1 y7)
        (Board x2 y7)
        (Board x3 y7)
        (Board x4 y7)
        (Board x5 y7)
        (Board x6 y7)
        (Board x7 y7)
        (Board x8 y7)
    )
)
(assert
    (distinct 
        (Board x0 y8)
        (Board x1 y8)
        (Board x2 y8)
        (Board x3 y8)
        (Board x4 y8)
        (Board x5 y8)
        (Board x6 y8)
        (Board x7 y8)
        (Board x8 y8)
    )
)

; Constraints for the 3x3 square
(assert
    (distinct 
        (Board x0 y0)
        (Board x0 y1)
        (Board x0 y2)
        (Board x1 y0)
        (Board x1 y1)
        (Board x1 y2)
        (Board x2 y0)
        (Board x2 y1)
        (Board x2 y2)
    )
)
(assert
    (distinct 
        (Board x3 y0)
        (Board x3 y1)
        (Board x3 y2)
        (Board x4 y0)
        (Board x4 y1)
        (Board x4 y2)
        (Board x5 y0)
        (Board x5 y1)
        (Board x5 y2)
    )
)
(assert
    (distinct 
        (Board x6 y0)
        (Board x6 y1)
        (Board x6 y2)
        (Board x7 y0)
        (Board x7 y1)
        (Board x7 y2)
        (Board x8 y0)
        (Board x8 y1)
        (Board x8 y2)
    )
)
(assert
    (distinct 
        (Board x0 y3)
        (Board x0 y4)
        (Board x0 y5)
        (Board x1 y3)
        (Board x1 y4)
        (Board x1 y5)
        (Board x2 y3)
        (Board x2 y4)
        (Board x2 y5)
    )
)
(assert
    (distinct 
        (Board x3 y3)
        (Board x3 y4)
        (Board x3 y5)
        (Board x4 y3)
        (Board x4 y4)
        (Board x4 y5)
        (Board x5 y3)
        (Board x5 y4)
        (Board x5 y5)
    )
)
(assert
    (distinct 
        (Board x6 y3)
        (Board x6 y4)
        (Board x6 y5)
        (Board x7 y3)
        (Board x7 y4)
        (Board x7 y5)
        (Board x8 y3)
        (Board x8 y4)
        (Board x8 y5)
    )
)
(assert
    (distinct 
        (Board x0 y6)
        (Board x0 y7)
        (Board x0 y8)
        (Board x1 y6)
        (Board x1 y7)
        (Board x1 y8)
        (Board x2 y6)
        (Board x2 y7)
        (Board x2 y8)
    )
)
(assert
    (distinct 
        (Board x3 y6)
        (Board x3 y7)
        (Board x3 y8)
        (Board x4 y6)
        (Board x4 y7)
        (Board x4 y8)
        (Board x5 y6)
        (Board x5 y7)
        (Board x5 y8)
    )
)
(assert
    (distinct 
        (Board x6 y6)
        (Board x6 y7)
        (Board x6 y8)
        (Board x7 y6)
        (Board x7 y7)
        (Board x7 y8)
        (Board x8 y6)
        (Board x8 y7)
        (Board x8 y8)
    )
)

;;;;;; --- END-CONSTRAINTS-1 ---

;;;;;; --- BEGIN-CONSTRAINTS-2 --- 

; ** Constraints for top left square **

; At most one of the yellow cells may contain a value larger than 4.
(assert
    (or
        (and
            (> (Board x0 y0) 4)
            (<= (Board x0 y2) 4)
            (<= (Board x2 y0) 4)
            (<= (Board x2 y2) 4)
        )
        (and
            (<= (Board x0 y0) 4)
            (> (Board x0 y2) 4)
            (<= (Board x2 y0) 4)
            (<= (Board x2 y2) 4)
        )
        (and
            (<= (Board x0 y0) 4)
            (<= (Board x0 y2) 4)
            (> (Board x2 y0) 4)
            (<= (Board x2 y2) 4)
        )
        (and
            (<= (Board x0 y0) 4)
            (<= (Board x0 y2) 4)
            (<= (Board x2 y0) 4)
            (> (Board x2 y2) 4)
        )
    )
)

;;;;;; --- END-CONSTRAINTS-2 ---



;;;;;; --- BEGIN-CONSTRAINTS-3 --- 

; ** Constraints for top right square **

; The sum of all rows in this square must be equal, i.e., 
; <6, 0> + <7, 0> + <8, 0> = <6, 1> + <7, 1> + <8, 1> = <6, 2> + <7, 2> + <8, 2>.
(assert
    (=
        (+ (Board x6 y0) (Board x7 y0) (Board x8 y0))
        (+ (Board x6 y1) (Board x7 y1) (Board x8 y1))
        (+ (Board x6 y2) (Board x7 y2) (Board x8 y2))
    )
)

;;;;;; --- END-CONSTRAINTS-3 ---



;;;;;; --- BEGIN-CONSTRAINTS-4 --- 

; ** Constraints for middle left square **

; For every corner cell of this square, one of the horizontally or
; vertically adjacent cells must equal the value plus 1.
(assert
    (or
        (and
            (= (Board x1 y3) (+ (Board x0 y3) 1))
            (not (= (Board x0 y4) (+ (Board x0 y3) 1)))
        )
        (and
            (= (Board x0 y4) (+ (Board x0 y3) 1))
            (not (= (Board x1 y3) (+ (Board x0 y3) 1)))
        )
    )
)

(assert
    (or
        (and
            (= (Board x1 y3) (+ (Board x2 y3) 1))
            (not (= (Board x2 y4) (+ (Board x2 y3) 1)))
        )
        (and
            (= (Board x2 y4) (+ (Board x2 y3) 1))
            (not (= (Board x1 y3) (+ (Board x2 y3) 1)))
        )
    )
)

(assert
    (or
        (and
            (= (Board x1 y5) (+ (Board x2 y5) 1))
            (not (= (Board x2 y4) (+ (Board x2 y5) 1)))
        )
        (and
            (= (Board x2 y4) (+ (Board x2 y5) 1))
            (not (= (Board x1 y5) (+ (Board x2 y5) 1)))
        )
    )
)

(assert
    (or
        (and
            (= (Board x1 y5) (+ (Board x0 y5) 1))
            (not (= (Board x0 y4) (+ (Board x0 y5) 1)))
        )
        (and
            (= (Board x0 y4) (+ (Board x0 y5) 1))
            (not (= (Board x1 y5) (+ (Board x0 y5) 1)))
        )
    )
)

;;;;;; --- END-CONSTRAINTS-4 ---



;;;;;; --- BEGIN-CONSTRAINTS-5 --- 

; ** Constraints for center square **

; Addition rule: <4, 3> + <5, 3> = 13
(assert
    (=
        (+ (Board x4 y3) (Board x5 y3))
        13
    )
)

; Division rule can be written as multiplication ==> <5,5> = 2 * <5,4>
(assert 
    (=
        (* (Board x5 y4) 2)
        (Board x5 y5)
    )
)

; Subtraction rule: <3, 5> − <4, 5> = 6
(assert
    (=
        (- (Board x3 y5) (Board x4 y5))
        6
    )
)

;;;;;; --- END-CONSTRAINTS-5 ---



;;;;;; --- BEGIN-CONSTRAINTS-6 --- 

; ** Constraints for center right square **

; The sum of the indicated cells must be equal to three times
; the value of the center cell.
(assert 
    (=
        (+ (Board x7 y3) (Board x6 y4) (Board x7 y5) (Board x8 y4))
        (* (Board x7 y4) 3)
    )
)

;;;;;; --- END-CONSTRAINTS-6 ---



;;;;;; --- BEGIN-CONSTRAINTS-7 --- 

; ** Constraints for bottom left square **

; Numbers must comply with the inequalities:

; <0, 6>  <  <0, 7>  <  <0, 8>
(assert
    (< (Board x0 y6) (Board x0 y7) (Board x0 y8))
)

; <1, 6>  <  <1, 7>  <  <1, 8>
(assert
    (< (Board x1 y6) (Board x1 y7) (Board x1 y8))
)

; <2, 6>  <  <2, 7>  <  <2, 8>
(assert
    (< (Board x2 y6) (Board x2 y7) (Board x2 y8))
)


;;;;;; --- END-CONSTRAINTS-7 ---



;;;;;; --- BEGIN-CONSTRAINTS-8 --- 

; ** Constraints for bottom middle square **

; For defining mod to check for even, we can use the following equation:
; c = 0 (mod 2)
; c - 0 = k*2
; c == k*2 for even
; c == k*2 + 1 for odd

; The k can take minimum value: 144 = (1+3+4)*(5+6+7)
; and maximum value: 289 = (4+7+6)*(3+5+9)
(declare-const k Int)
(assert (and (>= (* k 2) 144) (<= (* k 2) 289))) 

; Multiplying the sums of the two indicated columns gives an odd number
(assert
    (=
        (*
            (+ (Board x3 y6) (Board x3 y7) (Board x3 y8))
            (+ (Board x5 y6) (Board x5 y7) (Board x5 y8))
        )
        (+ (* k 2) 1)
    )
)

;;;;;; --- END-CONSTRAINTS-8 ---


;;;;;; --- BEGIN-CONSTRAINTS-9 --- 

; ** Constraints for bottom right square **

; Defining the k{1...10} varibales similar to constraint 8 for checking for even and odd
(declare-const k1 Int)
(declare-const k2 Int)
(declare-const k3 Int)
(declare-const k4 Int)
(declare-const k5 Int)
(declare-const k6 Int)
(declare-const k7 Int)
(declare-const k8 Int)
(declare-const k9 Int)
(declare-const k10 Int)
(assert (and (>= (* k1 2) 1) (<= (* k1 2) 9)))
(assert (and (>= (* k2 2) 1) (<= (* k2 2) 9)))
(assert (and (>= (* k3 2) 1) (<= (* k3 2) 9)))
(assert (and (>= (* k4 2) 1) (<= (* k4 2) 9)))
(assert (and (>= (* k5 2) 1) (<= (* k5 2) 9)))
(assert (and (>= (* k6 2) 1) (<= (* k6 2) 9)))
(assert (and (>= (* k7 2) 1) (<= (* k7 2) 9)))
(assert (and (>= (* k8 2) 1) (<= (* k8 2) 9)))
(assert (and (>= (* k9 2) 1) (<= (* k9 2) 9)))
(assert (and (>= (* k10 2) 1) (<= (* k10 2) 9)))

; either one of the values in the OR clause will become true in a single evaluation 
; as board's cell value can't be even and odd at the same time
(assert
    (or
        (and 
            (not
                (=
                    (Board x6 y6)
                    (* k1 2)
                )
            )
            (not 
                (=
                    (Board x8 y6)
                    (* k2 2)
                )
            )
            (not 
                (=
                    (Board x6 y8)
                    (* k3 2)
                )
            )  
            (not 
                (=
                    (Board x8 y8)
                    (* k4 2)
                )
            )      
            (=
                (Board x7 y7)
                (* k5 2)
            )
        )
        (and 
            (=
                (Board x6 y6)
                (* k6 2)
            )
            (=
                (Board x8 y6)
                (* k7 2)
            )
            (=
                (Board x6 y8)
                (* k8 2)
            )
            (=
                (Board x8 y8)
                (* k9 2)
            )
            (not
                (=
                    (Board x7 y7)
                    (* k10 2)
                )
            )
        )
    )
)

;;;;;; --- END-CONSTRAINTS-9 ---



;;;;;; --- BEGIN-CONSTRAINTS-DOMAIN ---

; Each cell may be assigned only to integer values between 1 and 9:

(assert (and (< (Board x0 y0) 10) (> (Board x0 y0) 0)))
(assert (and (< (Board x0 y1) 10) (> (Board x0 y1) 0)))
(assert (and (< (Board x0 y2) 10) (> (Board x0 y2) 0)))
(assert (and (< (Board x0 y3) 10) (> (Board x0 y3) 0)))
(assert (and (< (Board x0 y4) 10) (> (Board x0 y4) 0)))
(assert (and (< (Board x0 y5) 10) (> (Board x0 y5) 0)))
(assert (and (< (Board x0 y6) 10) (> (Board x0 y6) 0)))
(assert (and (< (Board x0 y7) 10) (> (Board x0 y7) 0)))
(assert (and (< (Board x0 y8) 10) (> (Board x0 y8) 0)))
(assert (and (< (Board x1 y0) 10) (> (Board x1 y0) 0)))
(assert (and (< (Board x1 y1) 10) (> (Board x1 y1) 0)))
(assert (and (< (Board x1 y2) 10) (> (Board x1 y2) 0)))
(assert (and (< (Board x1 y3) 10) (> (Board x1 y3) 0)))
(assert (and (< (Board x1 y4) 10) (> (Board x1 y4) 0)))
(assert (and (< (Board x1 y5) 10) (> (Board x1 y5) 0)))
(assert (and (< (Board x1 y6) 10) (> (Board x1 y6) 0)))
(assert (and (< (Board x1 y7) 10) (> (Board x1 y7) 0)))
(assert (and (< (Board x1 y8) 10) (> (Board x1 y8) 0)))
(assert (and (< (Board x2 y0) 10) (> (Board x2 y0) 0)))
(assert (and (< (Board x2 y1) 10) (> (Board x2 y1) 0)))
(assert (and (< (Board x2 y2) 10) (> (Board x2 y2) 0)))
(assert (and (< (Board x2 y3) 10) (> (Board x2 y3) 0)))
(assert (and (< (Board x2 y4) 10) (> (Board x2 y4) 0)))
(assert (and (< (Board x2 y5) 10) (> (Board x2 y5) 0)))
(assert (and (< (Board x2 y6) 10) (> (Board x2 y6) 0)))
(assert (and (< (Board x2 y7) 10) (> (Board x2 y7) 0)))
(assert (and (< (Board x2 y8) 10) (> (Board x2 y8) 0)))
(assert (and (< (Board x3 y0) 10) (> (Board x3 y0) 0)))
(assert (and (< (Board x3 y1) 10) (> (Board x3 y1) 0)))
(assert (and (< (Board x3 y2) 10) (> (Board x3 y2) 0)))
(assert (and (< (Board x3 y3) 10) (> (Board x3 y3) 0)))
(assert (and (< (Board x3 y4) 10) (> (Board x3 y4) 0)))
(assert (and (< (Board x3 y5) 10) (> (Board x3 y5) 0)))
(assert (and (< (Board x3 y6) 10) (> (Board x3 y6) 0)))
(assert (and (< (Board x3 y7) 10) (> (Board x3 y7) 0)))
(assert (and (< (Board x3 y8) 10) (> (Board x3 y8) 0)))
(assert (and (< (Board x4 y0) 10) (> (Board x4 y0) 0)))
(assert (and (< (Board x4 y1) 10) (> (Board x4 y1) 0)))
(assert (and (< (Board x4 y2) 10) (> (Board x4 y2) 0)))
(assert (and (< (Board x4 y3) 10) (> (Board x4 y3) 0)))
(assert (and (< (Board x4 y4) 10) (> (Board x4 y4) 0)))
(assert (and (< (Board x4 y5) 10) (> (Board x4 y5) 0)))
(assert (and (< (Board x4 y6) 10) (> (Board x4 y6) 0)))
(assert (and (< (Board x4 y7) 10) (> (Board x4 y7) 0)))
(assert (and (< (Board x4 y8) 10) (> (Board x4 y8) 0)))
(assert (and (< (Board x5 y0) 10) (> (Board x5 y0) 0)))
(assert (and (< (Board x5 y1) 10) (> (Board x5 y1) 0)))
(assert (and (< (Board x5 y2) 10) (> (Board x5 y2) 0)))
(assert (and (< (Board x5 y3) 10) (> (Board x5 y3) 0)))
(assert (and (< (Board x5 y4) 10) (> (Board x5 y4) 0)))
(assert (and (< (Board x5 y5) 10) (> (Board x5 y5) 0)))
(assert (and (< (Board x5 y6) 10) (> (Board x5 y6) 0)))
(assert (and (< (Board x5 y7) 10) (> (Board x5 y7) 0)))
(assert (and (< (Board x5 y8) 10) (> (Board x5 y8) 0)))
(assert (and (< (Board x6 y0) 10) (> (Board x6 y0) 0)))
(assert (and (< (Board x6 y1) 10) (> (Board x6 y1) 0)))
(assert (and (< (Board x6 y2) 10) (> (Board x6 y2) 0)))
(assert (and (< (Board x6 y3) 10) (> (Board x6 y3) 0)))
(assert (and (< (Board x6 y4) 10) (> (Board x6 y4) 0)))
(assert (and (< (Board x6 y5) 10) (> (Board x6 y5) 0)))
(assert (and (< (Board x6 y6) 10) (> (Board x6 y6) 0)))
(assert (and (< (Board x6 y7) 10) (> (Board x6 y7) 0)))
(assert (and (< (Board x6 y8) 10) (> (Board x6 y8) 0)))
(assert (and (< (Board x7 y0) 10) (> (Board x7 y0) 0)))
(assert (and (< (Board x7 y1) 10) (> (Board x7 y1) 0)))
(assert (and (< (Board x7 y2) 10) (> (Board x7 y2) 0)))
(assert (and (< (Board x7 y3) 10) (> (Board x7 y3) 0)))
(assert (and (< (Board x7 y4) 10) (> (Board x7 y4) 0)))
(assert (and (< (Board x7 y5) 10) (> (Board x7 y5) 0)))
(assert (and (< (Board x7 y6) 10) (> (Board x7 y6) 0)))
(assert (and (< (Board x7 y7) 10) (> (Board x7 y7) 0)))
(assert (and (< (Board x7 y8) 10) (> (Board x7 y8) 0)))
(assert (and (< (Board x8 y0) 10) (> (Board x8 y0) 0)))
(assert (and (< (Board x8 y1) 10) (> (Board x8 y1) 0)))
(assert (and (< (Board x8 y2) 10) (> (Board x8 y2) 0)))
(assert (and (< (Board x8 y3) 10) (> (Board x8 y3) 0)))
(assert (and (< (Board x8 y4) 10) (> (Board x8 y4) 0)))
(assert (and (< (Board x8 y5) 10) (> (Board x8 y5) 0)))
(assert (and (< (Board x8 y6) 10) (> (Board x8 y6) 0)))
(assert (and (< (Board x8 y7) 10) (> (Board x8 y7) 0)))
(assert (and (< (Board x8 y8) 10) (> (Board x8 y8) 0)))

;;;;;; --- END-CONSTRAINTS-DOMAIN ---



; Compute solution

(check-sat)



; Print solution, line by line

(get-value ((Board x0 y0)))
(get-value ((Board x1 y0)))
(get-value ((Board x2 y0)))
(get-value ((Board x3 y0)))
(get-value ((Board x4 y0)))
(get-value ((Board x5 y0)))
(get-value ((Board x6 y0)))
(get-value ((Board x7 y0)))
(get-value ((Board x8 y0)))
(get-value ((Board x0 y1)))
(get-value ((Board x1 y1)))
(get-value ((Board x2 y1)))
(get-value ((Board x3 y1)))
(get-value ((Board x4 y1)))
(get-value ((Board x5 y1)))
(get-value ((Board x6 y1)))
(get-value ((Board x7 y1)))
(get-value ((Board x8 y1)))
(get-value ((Board x0 y2)))
(get-value ((Board x1 y2)))
(get-value ((Board x2 y2)))
(get-value ((Board x3 y2)))
(get-value ((Board x4 y2)))
(get-value ((Board x5 y2)))
(get-value ((Board x6 y2)))
(get-value ((Board x7 y2)))
(get-value ((Board x8 y2)))
(get-value ((Board x0 y3)))
(get-value ((Board x1 y3)))
(get-value ((Board x2 y3)))
(get-value ((Board x3 y3)))
(get-value ((Board x4 y3)))
(get-value ((Board x5 y3)))
(get-value ((Board x6 y3)))
(get-value ((Board x7 y3)))
(get-value ((Board x8 y3)))
(get-value ((Board x0 y4)))
(get-value ((Board x1 y4)))
(get-value ((Board x2 y4)))
(get-value ((Board x3 y4)))
(get-value ((Board x4 y4)))
(get-value ((Board x5 y4)))
(get-value ((Board x6 y4)))
(get-value ((Board x7 y4)))
(get-value ((Board x8 y4)))
(get-value ((Board x0 y5)))
(get-value ((Board x1 y5)))
(get-value ((Board x2 y5)))
(get-value ((Board x3 y5)))
(get-value ((Board x4 y5)))
(get-value ((Board x5 y5)))
(get-value ((Board x6 y5)))
(get-value ((Board x7 y5)))
(get-value ((Board x8 y5)))
(get-value ((Board x0 y6)))
(get-value ((Board x1 y6)))
(get-value ((Board x2 y6)))
(get-value ((Board x3 y6)))
(get-value ((Board x4 y6)))
(get-value ((Board x5 y6)))
(get-value ((Board x6 y6)))
(get-value ((Board x7 y6)))
(get-value ((Board x8 y6)))
(get-value ((Board x0 y7)))
(get-value ((Board x1 y7)))
(get-value ((Board x2 y7)))
(get-value ((Board x3 y7)))
(get-value ((Board x4 y7)))
(get-value ((Board x5 y7)))
(get-value ((Board x6 y7)))
(get-value ((Board x7 y7)))
(get-value ((Board x8 y7)))
(get-value ((Board x0 y8)))
(get-value ((Board x1 y8)))
(get-value ((Board x2 y8)))
(get-value ((Board x3 y8)))
(get-value ((Board x4 y8)))
(get-value ((Board x5 y8)))
(get-value ((Board x6 y8)))
(get-value ((Board x7 y8)))
(get-value ((Board x8 y8)))

