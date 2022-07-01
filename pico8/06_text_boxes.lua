function _init()
  t=0
  p_ani={240,241,242,243}
  
  dirx={-1,1,0,0}
  diry={0,0,-1,1}
  
  _upd=update_game
  _drw=draw_game
  startgame()
 end
 
 function _update60()
  t+=1
  _upd()
 end
 
 function _draw()
  _drw()
  drawind()
 end
 
 function startgame()
  buttbuff=-1
  
  p_x=1
  p_y=1
  p_ox=0
  p_oy=0
  p_sox=0
  p_soy=0
  p_flip=false
  p_mov=nil
  p_t=0
  
  wind={}
  
  addwind(32,64,64,24,{"hello world","this is line 2"})
 end
 -->8
 --updates
 function update_game()
  dobuttbuff()
  dobutt(buttbuff)
  buttbuff=-1
 end
 
 function update_pturn()
  dobuttbuff()
  p_t=min(p_t+0.125,1)
 
  p_mov()
  
  if p_t==1 then
   _upd=update_game
  end
 end
 
 function update_gameover()
 
 end
 
 function mov_walk()
  p_ox=p_sox*(1-p_t)
  p_oy=p_soy*(1-p_t)
 end
 
 function mov_bump()
  local tme=p_t 
  if p_t>0.5 then
   tme=1-p_t
  end
  p_ox=p_sox*(tme)
  p_oy=p_soy*(tme) 
 end
 
 function dobuttbuff()
  if buttbuff==-1 then
   buttbuff=getbutt()
  end
 end
 
 function getbutt()
  for i=0,5 do
   if btnp(i) then
    return i
   end
  end
  return -1
 end
 
 function dobutt(butt)
  if butt<0 then return end
  if butt<4 then
   moveplayer(dirx[butt+1],diry[butt+1])
   return
  end
  -- menu button
 end
 -->8
 --draws
 function draw_game()
  cls(0)
  map()
  drawspr(getframe(p_ani),p_x*8+p_ox,p_y*8+p_oy,10,p_flip)
 end
 
 function draw_gameover()
 end
 -->8
 --tools
 
 function getframe(ani)
  return ani[flr(t/15)%#ani+1]
 end
 
 function drawspr(_spr,_x,_y,_c,_flip)
  palt(0,false)
  pal(6,_c)
  spr(_spr,_x,_y,1,1,_flip)
  pal() 
 end
 
 function rectfill2(_x,_y,_w,_h,_c)
  rectfill(_x,_y,_x+_w-1,_y+_h-1,_c)
 end
 -->8
 --gameplay
 
 function moveplayer(dx,dy)
  local destx,desty=p_x+dx,p_y+dy
  local tle=mget(destx,desty)
  
  if dx<0 then
   p_flip=true
  elseif dx>0 then
   p_flip=false   
  end
   
  if fget(tle,0) then
   --wall
   p_sox,p_soy=dx*8,dy*8
   p_ox,p_oy=0,0
   p_t=0
   _upd=update_pturn
   p_mov=mov_bump
   if fget(tle,1) then
    trig_bump(tle,destx,desty)
   end
  else
   sfx(63)
   p_x+=dx
   p_y+=dy
        
   p_sox,p_soy=-dx*8,-dy*8
   p_ox,p_oy=p_sox,p_soy
   p_t=0
   _upd=update_pturn
   p_mov=mov_walk
  end
 end
 
 function trig_bump(tle,destx,desty)
  if tle==7 or tle==8 then
   --vase
   sfx(59)
   mset(destx,desty,1)
  elseif tle==10 or tle==12 then
   --chest
   sfx(61)
   mset(destx,desty,tle-1)
  elseif tle==13 then
   --door
   sfx(62)
   mset(destx,desty,1)
  end
 end
 -->8
 --ui
 
 function addwind(_x,_y,_w,_h,_txt)
  local w={x=_x,
           y=_y,
           w=_w,
           h=_h,
           txt=_txt}
  add(wind,w)
  return w
 end
 
 function drawind()
  for w in all(wind) do
   local wx,wy,ww,wh=w.x,w.y,w.w,w.h
   rectfill2(wx,wy,ww,wh,0)
   rectfill2(wx+1,wy+1,ww-2,wh-2,6)
   rectfill2(wx+2,wy+2,ww-4,wh-4,0)
   wx+=4
   wy+=4
   clip(wx,wy,ww-8,wh-8)
   for i=1,#w.txt do
    local txt=w.txt[i]
    print(txt,wx,wy,6)
    wy+=6
   end
  end
 end