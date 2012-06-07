-- Merge Sort
msort :: (Ord a) => [a] -> [a]
msort [] = []
msort xs
  | length xs == 1 = xs
  | otherwise = merge fhalf shalf
                where
                  (f,s) = split xs
                  fhalf = msort f
                  shalf = msort s

split :: (Ord a) => [a] -> ([a],[a])
split xs = splitAt center xs
             where 
               center = (length xs) `div` 2

merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
  | x < y   = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys

