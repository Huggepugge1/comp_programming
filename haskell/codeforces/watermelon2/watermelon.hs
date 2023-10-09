import Text.Printf

solve :: Int -> String
solve x 
  | x `mod` 2 == 0  && x > 2 = "YES"
  | otherwise = "NO"

main :: IO ()
main = do
    x <- getLine
    printf "%s\n" $ solve (read x :: Int)
