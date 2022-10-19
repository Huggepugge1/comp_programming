module Planktonfarmen

open System

let a = Console.ReadLine() |> int
let b = Console.ReadLine() |> int
let c = Console.ReadLine().Split(" ")
let mutable d = []

for s in c do
    d <- [(s) |> int] |> List.append d

let rec merge (s1: 'a list) (s2:'a list) : 'a list =
    match s1, s2 with
    | [],L -> L
    | L, [] -> L
    | x1::t1,x2::t2  when x1 < x2 -> x1::merge t1 (x2::t2)
    | l1, x2::t2 -> x2::merge l1 t2;;

// Helper function for bisect. When called with a list followed by two empty lists,
// return a tuple of two lists, each containing about half the items in the original list.
// (When the later lists are not empty: return a tuple containing two lists, the second
// and third inputs each concatenated with about half the first list.)
let rec bisectInt (w: 'a list) (r: 'a list) (l:'a list) : ('a list * 'a list) = 
    match w with
    | [] -> (r,l)
    | [x] -> (x::r,l)
    | x::y::t -> bisectInt t (x::r) (y::l);;

// Return a tuple of two lists each with about half the items in the original.
let bisect w = bisectInt w [] [];;

let rec mergeSort (l:'a list) : 'a list =
    match l with
    | [] -> []
    | [x] -> [x]
    | w ->
        let (l,r) = bisect(w)
        let ls = mergeSort(l)
        let rs = mergeSort(r)
        merge ls rs;;

let d2 = mergeSort d

let mutable p1 = 0
let mutable p2 = b-1
let mutable ans = 0

while p1 < p2 do
    if d2.[p1] * d2.[p2] < a then
        p1 <- p1 + 1
    else
        p1 <- p1 + 1
        p2 <- p2 - 1
        ans <- ans + 1

Console.Write("{0}\n", ans)
