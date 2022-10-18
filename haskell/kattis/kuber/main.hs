cubes :: Int -> Int -> Int
cubes n m
    | n == 0 = m
    | otherwise = cubes (n - 1) (m + (n*n*n))


main :: IO ()
main = do 
    interact $ cubes . read 0