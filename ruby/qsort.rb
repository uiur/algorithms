class Array
  def qsort
    return self if self.size <= 1
    pivot = self.first
    smaller, larger = self[1..-1].partition {|item| item < pivot }
    
    (smaller.qsort) + [pivot] + (larger.qsort)
  end
end
